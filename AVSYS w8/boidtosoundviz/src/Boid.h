//
//  Boid.h
//  This class represents a "boid" object that can be moved
//  by calling one of the "movement" functions.
//
//  Created by Jeffrey Crouse on 3/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "ofMain.h"

#define TAIL_LENGTH 500


class Boid {
public:
    
    float r;                // Size of the boid
    ofPoint _noiserow;      // which row to fetch noise from for addNoise()
    ofPoint vel;            // The velocity of the boid
    ofPoint loc;            // The location of the boid
    ofPoint acc;            // The acceleration of the boid
    float maxspeed;         // The max vel val (in either dir)
    float maxforce;         // The max allowed accel in any 1 frame
    vector<ofPoint> tail;   // A list of points where the boid has been
    
    //
    // Basic Functions
    //
    
    // Initialize the Boid
    void setup(float size, float initialVelocity);
    
    // Apply the acceleration/velocity/loop around screen if necessary
    void update();
    
    // Draw the boid onto the screen 
    void draw(int j,float sample);
    
    
    //
    // Movement Functions
    //
    
    // Add a bit of noise to the acceleration
    void addNoise();
    
    // Tell the boid to avoid p
    void acelerateAwayFrom(ofPoint p, float strength=1);
    
    
    // Accelerates the Boid towards the target
    void accelerateTowards(ofPoint target, float strength=1);
};

