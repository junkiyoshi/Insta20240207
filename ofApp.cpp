#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(100);
	ofSetLineWidth(1.5);
	ofNoFill();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_MULTIPLY);
}

//--------------------------------------------------------------
void ofApp::update() {
		
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	this->cam.begin();
	ofRotateX(180);

	this->drawTorus(200, 100, 128, 128);

	this->cam.end();

	/*
	int start = 1;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
// このメソッドはCopilotによって自動生成されました。
void ofApp::drawTorus(float radius, float tubeRadius, int numc, int numt) {

	float twopi = 2 * PI;
	float p = 0;
	float t = 0;
	float x = 0;
	float y = 0;
	float z = 0;
	float s = 0;
	float u = 0;
	float v = 0;

	for (int i = 0; i < numc; i++) {

		ofBeginShape();
		for (int j = 0; j <= numt; j++) {

			for (int k = 1; k >= 0; k--) {

				p = (i + k) % numc;
				t = (j + 1) % numt;

				x = (radius + tubeRadius * cos(p * twopi / numc)) * cos(t * twopi / numt);
				y = (radius + tubeRadius * cos(p * twopi / numc)) * sin(t * twopi / numt);
				z = tubeRadius * sin(p * twopi / numc);
				s = (i + k) / (float)numc;
				u = (j + 1) / (float)numt;
				v = p / (float)numc;

				// 以下の5行を自身で追加
				auto noise_value = ofNoise(x * 0.005, y * 0.005, z * 0.005, ofGetFrameNum() * 0.025);
				auto noise_radius = tubeRadius * noise_value;
				auto noise_x = (radius + noise_radius * cos(p * twopi / numc)) * cos(t * twopi / numt);
				auto noise_y = (radius + noise_radius * cos(p * twopi / numc)) * sin(t * twopi / numt);
				auto noise_z = noise_radius * sin(p * twopi / numc);

				// 以下の1行を自身で編集
				ofVertex(noise_x, noise_y, 0);
			}
		}
		ofEndShape();
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}