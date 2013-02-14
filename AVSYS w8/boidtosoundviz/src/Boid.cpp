//
//  Boid.cpp
//  emptyExample
//
//  Created by Jeffrey Crouse on 3/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Boid.h"



// -------------------------------
void Boid::setup(float size, float initialVelocity) {
    r = size;
    maxspeed = 4.0;
    maxforce = 0.1;
    
    loc.x = ofRandomWidth();
    loc.y = ofRandomHeight();
    vel.x = ofRandom(-initialVelocity, initialVelocity);
    vel.y = ofRandom(-initialVelocity, initialVelocity);
    
    _noiserow.x = ofRandomf();
    _noiserow.y = ofRandomf();
}

// -------------------------------
void Boid::update() {
    
    vel += acc;
    vel.x = ofClamp(vel.x, -maxspeed, maxspeed);  // Limit speed
    vel.y = ofClamp(vel.y, -maxspeed, maxspeed);  // Limit speed
    loc += vel;
    
    if(vel.length() > 0.2)
        tail.push_back( loc );
    if(tail.size() > TAIL_LENGTH)
        tail.erase( tail.begin() );
    
    acc = 0;  // Reset accelertion to 0 each cycle
    
    if (loc.x < -r) loc.x = ofGetWidth()+r;
    if (loc.y < -r) loc.y = ofGetHeight()+r;
    if (loc.x > ofGetWidth()+r) loc.x = -r;
    if (loc.y > ofGetHeight()+r) loc.y = -r;
}


// -------------------------------
void Boid::draw(int j,float sample) 
{
    // Draw a triangle rotated in the direction of velocity
    float angle = (float)atan2(-vel.y, vel.x);
    float theta =  -1.0*angle;
    float heading2D = ofRadToDeg(theta)+90;
    
    ofEnableAlphaBlending();
    ofNoFill();
    ofPushMatrix();
    ofTranslate(loc.x, loc.y);
    ofRotateZ(heading2D);
    
    ofScale(0.1,0.1);
    ofBeginShape();
    
    ofVertex(100-356+j      , -256      +sample     );
    ofVertex(512-356+sample , -256      +100    +j  );
    ofVertex(612-356-j      , -256 + 512 + sample   );
    ofVertex(200-356-sample , -256      +612    -j  );
    
    ofEndShape(true);
    ofPopMatrix();
    
    glBegin(GL_POINTS);
    for(int i=0; i<tail.size(); i++) {
        float alpha = ofMap(i, 0, tail.size(), 0, 255);
        ofSetColor(255, alpha);
        glVertex2f(tail[i].x, tail[i].y);
    }
    glEnd();
    
    ofDisableAlphaBlending();
}

// -------------------------------
void Boid::addNoise() 
{
    ofPoint noise;
    noise.x = ofSignedNoise(ofGetFrameNum() / 100.0, _noiserow.x);
    noise.y = ofSignedNoise(ofGetFrameNum() / 100.0, _noiserow.y);
    
    acc += (noise/40.0);
}

// -------------------------------
void Boid::acelerateAwayFrom(ofPoint target, float strength) 
{
    float dist = ofDist(target.x, target.y, loc.x, loc.y);
    
    ofPoint steer = loc - target; // A vector pointing from away from the target
    
    steer /= dist;   // normalize
    steer /= dist;   // Weight by distance
    
    steer *= strength;
    
    steer.x = ofClamp(steer.x, -maxforce, maxforce); // Limit to maximum steering force
    steer.y = ofClamp(steer.y, -maxforce, maxforce); 
    
    acc += steer;
}

// -------------------------------
void Boid::accelerateTowards(ofPoint target, float strength) 
{
    // Distance from the target is the magnitude of the vector
    float dist = ofDist(target.x, target.y, loc.x, loc.y);   
    if(dist < 200)
    {
        ofPoint steer = target - loc;  // A vector pointing from the Boid to the target

        steer /= dist; // Normalize steer

        steer *= strength * dist;
        steer -= vel;
        steer.x = ofClamp(steer.x, -maxforce, maxforce); // Limit to maximum steering force
        steer.y = ofClamp(steer.y, -maxforce, maxforce); 

        acc += steer;
    }
}


