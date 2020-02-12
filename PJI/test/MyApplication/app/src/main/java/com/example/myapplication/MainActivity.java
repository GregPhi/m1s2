package com.example.myapplication;

import android.content.Intent;
import android.graphics.Bitmap;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;

import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.firebase.ml.vision.FirebaseVision;
import com.google.firebase.ml.vision.common.FirebaseVisionImage;
import com.google.firebase.ml.vision.label.FirebaseVisionImageLabel;
import com.google.firebase.ml.vision.label.FirebaseVisionImageLabeler;
import com.google.firebase.ml.vision.label.FirebaseVisionOnDeviceImageLabelerOptions;

import java.util.List;

public class MainActivity extends BaseActivity implements View.OnClickListener {
    private Bitmap mBitmap;
    private ImageView mImageView;
    private TextView mTextView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mTextView = findViewById(R.id.textView);
        mImageView = findViewById(R.id.imageView);
        findViewById(R.id.btn_device).setOnClickListener(this);
        findViewById(R.id.btn_cloud).setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        mTextView.setText(null);
        switch (view.getId()) {
            case R.id.btn_device:
                if (mBitmap != null) {

//Configure the detector//

                    FirebaseVisionOnDeviceImageLabelerOptions options = new FirebaseVisionOnDeviceImageLabelerOptions.Builder()

//Set the confidence threshold//

                            .setConfidenceThreshold(0.7f)
                            .build();

//Create a FirebaseVisionImage object//

                    FirebaseVisionImage image = FirebaseVisionImage.fromBitmap(mBitmap);

//Create an instance of FirebaseVisionLabelDetector//

                    FirebaseVisionImageLabeler detector =
                            FirebaseVision.getInstance().getOnDeviceImageLabeler(options);

//Register an OnSuccessListener//

                    detector.processImage(image).addOnSuccessListener(new OnSuccessListener<List<FirebaseVisionImageLabel>>() {
                        @Override

//Implement the onSuccess callback//

                        public void onSuccess(List<FirebaseVisionImageLabel> labels) {
                            for (FirebaseVisionImageLabel label : labels) {

//Display the label and confidence score in our TextView//

                                mTextView.append(label.getText() + "\n");
                                mTextView.append(label.getConfidence() + "\n\n");
                            }
                        }

//Register an OnFailureListener//

                    }).addOnFailureListener(new OnFailureListener() {
                        @Override
                        public void onFailure(@NonNull Exception e) {
                            mTextView.setText(e.getMessage());
                        }
                    });
                }
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (resultCode == RESULT_OK) {
            switch (requestCode) {
                case RC_STORAGE_PERMS1:
                    checkStoragePermission(requestCode);
                    break;
                case RC_SELECT_PICTURE:
                    Uri dataUri = data.getData();
                    String path = MyHelper.getPath(this, dataUri);
                    if (path == null) {
                        mBitmap = MyHelper.resizeImage(imageFile, this, dataUri, mImageView);
                    } else {
                        mBitmap = MyHelper.resizeImage(imageFile, path, mImageView);
                    }
                    if (mBitmap != null) {
                        mTextView.setText(null);
                        mImageView.setImageBitmap(mBitmap);
                    }
                    break;

            }
        }
    }
}