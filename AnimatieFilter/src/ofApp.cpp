#include "ofApp.h"

#define PIN_BUTTON 2

//--------------------------------------------------------------
void ofApp::setup(){
	cam.listDevices();
	cam.setDeviceID(0);
	cam.setup(ofGetWidth(), ofGetHeight());
	
	//ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
	//arduino.connect("/dev/arduino");

	//arduino.sendFirmwareVersionRequest();

	drawAnimationFaseIdle = true;

	//Dakraken.load("Fase8_Reward_169.png");

	Soundfaseidle.load("Blubgeluid.wav");
	Soundfase1.load("RocketBoost.wav");

	
//*Alle png bestanden voor alle animaties inladen*//
	for (int i = 0; i < FaseIdle; i++) {
		//ofLogNotice() << "Loading fase0 = " << i << endl;
		//FaseIdlePlayer[i].load("Fase1_Instructie_000" + ofToString(i) + ".png");
	}

	for (int i = 0; i < Flesje; i++) {
		//ofLogNotice() << "Loading fase1 = " << i << endl;
		//FlesjePlayer[i].load("Fase2_BottleFlip_v2__000" + ofToString(i) + ".png");
	}

	for (int i = 0; i < Fase1; i++) {
		//ofLogNotice() << "Loading fase1 = " << i << endl;
		//Fase1Player[i].load("Fase3_Motor_000" + ofToString(i) + ".png");
	}
	
	for (int i = 0; i < Fase2; i++) {
		//ofLogNotice() << "Loading fase2 = " << i << endl;
		//Fase2Player[i].load("Fase4_Schudden_000" + ofToString(i) + ".png");
	}

	for (int i = 0; i < Fase3; i++) {
		//ofLogNotice() << "Loading fase3 = " << i << endl;
		//Fase3Player[i].load("Fase5_Rook_000" + ofToString(i) + ".png");
	}

	for (int i = 0; i < Fase4; i++) {
		//ofLogNotice() << "Loading fase4 = " << i << endl;
		//Fase4Player[i].load("Fase6_Vuur_000" + ofToString(i) + ".png");
	}

	for (int i = 0; i < Animatie; i++) {
		ofLogNotice() << "Loading Animation  " << i << endl;
		OpstijgPlayer[i] = new ofImage();
		OpstijgPlayer[i]->load("Fase8_Reward_" + ofToString(i) + ".png");
	}

	radius1 = 40;
	location.x = ofGetHeight() - 60;

	color = ofColor(17, 182, 255, 255);
}

//--------------------------------------------------------------
void ofApp::update() {
	cam.update();
	ofSoundUpdate();
	//arduino.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.draw(0, 0);
	ofSetColor(color);
	ofDrawRectangle(100, location.x, radius1, waterlevel);
	ofSetColor(ofColor::white);
	
	Soundfaseidle.setLoop(true);
	Soundfase1.setLoop(true);

	//Dakraken.draw(0, 0);


//*Flesje Idle (Geen Speler)*//
	if (drawAnimationFaseIdle) {
		FaseIdlePlayer[currentfaseidleanimatie].draw(0, ofGetHeight() - 1080);
	}

	if (ofGetElapsedTimeMillis() - lastfaseidleanimatietime > 50 && drawAnimationFaseIdle) {
		lastfaseidleanimatietime = ofGetElapsedTimeMillis();

		currentfaseidleanimatie++;
		if (currentfaseidleanimatie == 0) {
			if (!Soundfaseidle.isPlaying()) {
				Soundfaseidle.play();
			}
		}
		//ofLog() << "currentfase0animatie=" << currentfase0animatie << endl;
		if (currentfaseidleanimatie > 30) {
			currentfaseidleanimatie = 0;
		}
	} 

//*Flesje van Idle naar Fase 1*//
	if (drawAnimationFlesje) {
		FlesjePlayer[currentFlesjeanimatie].draw(0, ofGetHeight() - 1080);
	}

	if (ofGetElapsedTimeMillis() - lastFlesjeanimatietime > 50 && drawAnimationFlesje) {
		lastFlesjeanimatietime = ofGetElapsedTimeMillis();

		currentFlesjeanimatie++;
		//ofLog() << "currentFlesjeanimatie =" << currentFlesjeanimatie << endl;
		if (currentFlesjeanimatie > 23) {
			currentFlesjeanimatie = 0;
			drawAnimationFlesje = false;
			drawAnimationFase1 = true;
		}
	}

//*Als je 1/4 van het raketje gevuld hebt begint een moter bericht af te spelen en een klein beetje te trillen*//
	if (drawAnimationFase1) {
			Fase1Player[currentfase1animatie].draw(0, ofGetHeight() - 1080);
			drawAnimationFlesje = false;
		}

	if (ofGetElapsedTimeMillis() - lastfase1animatietime > 24 && drawAnimationFase1) {
			lastfase1animatietime = ofGetElapsedTimeMillis();

			currentfase1animatie++;
			if (currentfase1animatie == 0) {
				if (!Soundfase1.isPlaying()) {
					Soundfase1.play();
				}
			}
			//ofLog() << "currentfase1animatie=" << currentfase1animatie << endl;
			if (currentfase1animatie > 23) {
				currentfase1animatie = 0;
			}
		}

//*Als je 2/4 van het raketje gevuld hebt begint een moter bericht harder af te spelen en meer te trillen*//
	if (drawAnimationFase2) {
		Fase2Player[currentfase2animatie].draw(0, ofGetHeight() - 1080);
		drawAnimationFase1 = false;
	}

	if (ofGetElapsedTimeMillis() - lastfase2animatietime > 24 && drawAnimationFase2) {
		lastfase2animatietime = ofGetElapsedTimeMillis();

		currentfase2animatie++;
		//ofLog() << "currentfase2animatie=" << currentfase2animatie << endl;
		if (currentfase2animatie > 11) {
			currentfase2animatie = 0;
		}
	}

//*Als je 3/4 van het raketje gevuld hebt begint een moter bericht harder af te spelen en meer te trillen*//
	if (drawAnimationFase3) {
		Fase3Player[currentfase3animatie].draw(0, ofGetHeight() - 1080);
		drawAnimationFase2 = false;
	}

	if (ofGetElapsedTimeMillis() - lastfase3animatietime > 24 && drawAnimationFase3) {
		lastfase3animatietime = ofGetElapsedTimeMillis();

		currentfase3animatie++;
		ofLog() << "currentfase3animatie=" << currentfase3animatie << endl;
		if (currentfase3animatie > 16) {
			currentfase3animatie = 0;
		}
	}

//*Als je 4/4 van het raketje gevuld hebt begint een moter bericht harder af te spelen en meer te trillen*//
	if (drawAnimationFase4) {
		Fase4Player[currentfase4animatie].draw(0, ofGetHeight() - 1080);
		drawAnimationFase3 = false;
	}

	if (ofGetElapsedTimeMillis() - lastfase4animatietime > 24 && drawAnimationFase4) {
		lastfase4animatietime = ofGetElapsedTimeMillis();

		currentfase4animatie++;
		//ofLog() << "currentfase2animatie=" << currentfase2animatie << endl;
		if (currentfase4animatie > 14) {
			currentfase4animatie = 0;
		}
	}


//*Uiteindelijk finale animatie na genoeg te drinken*//
	if (drawAnimationOpstijgen) {
		OpstijgPlayer[currentopstijganimatie]->draw(0, ofGetHeight() - 1080);
		drawAnimationFase4 = false;
	}

	if (ofGetElapsedTimeMillis() - lastopstijganimatietime > 24 && drawAnimationOpstijgen) {
		lastopstijganimatietime = ofGetElapsedTimeMillis();
		
		currentopstijganimatie++;
		//ofLog() << "currentopstijganimatie=" << currentopstijganimatie << endl;
		if (currentopstijganimatie > 185) {
			currentopstijganimatie = 0;
			drawAnimationOpstijgen = false;
			drawAnimationFaseIdle = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == '0') {
		waterlevel = 0;
		drawAnimationFaseIdle = true;
	}
	else if (key == '1') {
		waterlevel = 0;
		drawAnimationFaseIdle = false;
		drawAnimationFlesje = true;
	}
	else if (key == '2') { 
		waterlevel = -20;
		drawAnimationFlesje = false;
		drawAnimationFase1 = true;
	}
	else if (key == '3') {
		waterlevel = -50;
		drawAnimationFase1 = false;
		drawAnimationFase2 = true;
	}
	else if (key == '4') {
		waterlevel = -70;
		drawAnimationFase2 = false;
		drawAnimationFase3 = true;
	}
	else if (key == '5') {
		waterlevel = -110; 
		drawAnimationFase3 = false;
		drawAnimationFase4 = true;
	}
	else if (key == ' ') {
		waterlevel = 0;
		drawAnimationOpstijgen = true;
		drawAnimationFase4 = false;
	}

}

/*void ofApp::setupArduino(const int& version) {
	ofLogNotice() << "Arduino initialized" << endl;
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.sendDigitalPinMode(PIN_BUTTON, ARD_INPUT);
	//arduino.sendAnalogPinReporting(PIN_POTMETER, ARD_ANALOG);

	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
	//ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::digitalPinChanged(const int& pin) {
	int value = arduino.getDigital(pin);
	ofLogVerbose() << "Digital pin" << pin << " changed to " << value << endl;
	if (pin == PIN_BUTTON && value == 1) {
		waterlevel = 0;
		drawAnimationOpstijgen = true;
		drawAnimationFase4 = false;
	}
} */