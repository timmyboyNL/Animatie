#pragma once

#include "ofMain.h"

// grote van arrays plaatjes aangeven //


#define FaseIdle 31
#define Flesje 24
#define Fase1 24
#define Fase2 12
#define Fase3 17
#define Fase4 15
#define Animatie 186


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		ofVideoGrabber cam;
		
		ofSoundPlayer Soundfaseidle;
		ofSoundPlayer Soundfase1;
		
		ofImage FaseIdlePlayer[FaseIdle];
		ofImage FlesjePlayer[Flesje];
		ofImage Fase1Player[Fase1];
		ofImage Fase2Player[Fase2];
		ofImage Fase3Player[Fase3];
		ofImage Fase4Player[Fase4];
		ofImage* OpstijgPlayer[Animatie];
		//ofImage Dakraken;

		int currentfaseidleanimatie;
		int currentFlesjeanimatie;
		int currentfase1animatie;
		int currentfase2animatie;
		int currentfase3animatie;
		int currentfase4animatie;
		int currentopstijganimatie;

		long lastfaseidleanimatietime;
		long lastFlesjeanimatietime;
		long lastfase1animatietime;
		long lastfase2animatietime;
		long lastfase3animatietime;
		long lastfase4animatietime;
		long lastopstijganimatietime;

		bool drawAnimationFaseIdle;
		bool drawAnimationFlesje;
		bool drawAnimationFase1;
		bool drawAnimationFase2;
		bool drawAnimationFase3;
		bool drawAnimationFase4;
		bool drawAnimationOpstijgen;

	
		
		ofPoint location;
		int radius1;

		int waterlevel; //aka radius2

		ofColor color;

		//ofArduino arduino;

		//void setupArduino(const int& version);

		//void digitalPinChanged(const int& pin);
};
