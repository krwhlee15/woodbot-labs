# Design Decisions: Sensors
## Objective
We like to select a set of sensors that would be necessary for Woodbot to solve a particular problem. 
Depending on sets of sensors we pick, we can do state estimations which maybe necessary for our applications.

### We like to 

- Narrow down sets of sensors that meet necessity and sufficiency
- Visit each option for potential use cases (applications, state estimations)
- Reduce work loads for the later labs (by eliminating infeasible sets of sensors)
- Conduct design engineering decisions with proper supports

This will require you to fill out highlighted parts for full credits.

***

## List of sensors:
- Touch sensor
- Distance sensor
- Camera
- Positional Encoder
- Inertial Measurement Unit (IMU)
- GPS
- Altitude sensor
- Pressure sensor
- Current sensor
- Voltage sensor
- 

***

## Option 1: One Touch Sensor (Example)
If Woodbot has only one touch sensor:
### What kind of information can we get?

>- Binary (boolean) data
>- Contact detections
>- Obstacle and wall detections

### What state can we estimate? Do we need something else to do so?
>- If there is a physical contact or not
>- Cannot estimate robot local or global states
>- We need a rigid wall and physical contacts should be allowed


### What kind of problems can we solve? (applications, use cases, examples)
>- Maze solving (Right Hand Rule)
>- Useless Box Leave Me Alone Woodbot 

***
## Option 2: Two Touch  sensors
If Woodbot has only one touch sensor:

### What kind of information can we get? 
>- 2 Binary (boolean) data
>- Contact detections in 2 planes
>- Obstacle and wall detections

### What state can we estimate?
>- If there is a physical contact or not
>- Cannot estimate robot local or global states
>- We need a rigid wall and physical contacts should be allowed

### What kind of problems can we solve? (applications, use cases, examples)

>- Maze solving 
>- A box that requires the contact points of 2 people
>- A simple puzzle game

***
## Option 3: Camera
If Woodbot has only a camera:

### What kind of information can we get?
>- Objects in front of the woodbot
>- The terrain in front of the woodbot
>- Light levels and distance

### What state can we estimate? Do we need something else to do so?
>- If there is an object in front of the woodbot
>- If there is a path forward that the woodbot can take

### What kind of problems can we solve? (applications, use cases, examples)
>- Can identify certain objects and go towards them
>- Can navigate terrain more effectively

***

## Option 4: Encoder
If Woodbot has only positional encoders on each wheel:

### What kind of information can we get? 
>- The positions of the woodbot

### What state can we estimate? Do we need something else to do so?
>- If the woodbot is moving or not
>- The direction the woodbot is facing

### What kind of problems can we solve? (applications, use cases, examples)
>- Given a flat terrain or a terrain that does not involve obstacles, can go to a coordinate and come back
>- Can run a race if the track is known beforehand

***

## Option 5: Two Lidars and IMU
If Woodbot has two lidars and IMU:

### What kind of information can we get? 
>- Objects in front of the woodbot
>- Distance of terrain in front and around the woodbot
>- Awareness of everything in 2 dimensions

### What state can we estimate? Do we need something else to do so?
>- If there is something within a certain range
>- If the woodbot is moving

### What kind of problems can we solve? (applications, use cases, examples)
>- Can navigate terrain even better than before
>- Can deliver a payload to a certain location

***


## Option 6: GPS + IMU
If Woodbot has GPS and IMU:

### What kind of information can we get? 
>- Location of the woodbot
>- The speed of the woodbot

### What state can we estimate? Do we need something else to do so?
>- If the woodbot is moving
>- The location of the woodbot
>- The direction of the woodbot

### What kind of problems can we solve? (applications, use cases, examples)
>- Can create a robot to drive to a certain location
>- Can navigate a known path
>- If the location of a trapped person is known, can deliver objects to that person

***
## Design Decisions:
Now we like to narrow down and make decisions on which set of sensors we like to use.

### Requirements
>- Navigation in an arena (2D plane)
>- A map and an initial state are given
>- Using affordable components and a microprocessor
>- Indoor

### Decisions
>- Since this is a navigation problem, we like to have a full state feedback, Option 1 and 2 are insufficient for our problem.
>- Since indoor, Option 6 is not viable
>- Since the map and initial states are given, Option 3, 4, and 5 are possible
>- Since we are using a microprocessor and we like to make the system affordable, Option 3 camera is less attractive

>- Option 4 and 5 meets our requirements
>- Option 4 is more affordable because we only need two sensors, but this will be an open loop state estimation
>- Option 5 requires more sensing, but we can do a close loop state estimation

#### My Conclusion: I go with Option 4 and 5


### Still Unknown, Things to be analyzed and decided later

>- We don't know whether open/close loop state estimators are necessary for us because our mathematical model does not capture uncertainty in the system now.
>- We don't know what state estimators we should use. We need to simulate uncertainties in the system to test out.

