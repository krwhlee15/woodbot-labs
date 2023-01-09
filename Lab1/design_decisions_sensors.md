# Design Decisions: Sensors
## Objective
We like to select a set of sensors that would be necessary for Woodbot to solve a particular problem. 
Depending on sets of sensors we pick, we can do state estimations which maybe necessary for our applications.

### We like to 

- Narrow down sets of sensors that meets necessity and sufficiency
- Visit each options for potential use cases (applications, state estimations)
- Reduce work loads for the later labs (by eliminating infeasible sets of sensors)
- Conduct design engineering decisions with proper supports.

This will require you to fill out highlighted parts for full credits.

***

## List of sensors:
- Touch sensor
- Distance sensor
- Camera
- Positional Encoder
- Inertial Measurement Unit (IMU)
- GPS

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
>- *Your answer here*
>-

### What state can we estimate?
>-  *Your answer here*
>- 

### What kind of problems can we solve? (applications, use cases, examples)

>- *Your answer here*
>- 

***
## Option 3: Camera
If Woodbot has only a camera:

### What kind of information can we get?
>- 
>-

### What state can we estimate? Do we need something else to do so?
>- 
>-

### What kind of problems can we solve? (applications, use cases, examples)
>- 
>- 

***

## Option 4: Encoder
If Woodbot has only positional encoders on each wheel:

### What kind of information can we get? 
>- 
>-

### What state can we estimate? Do we need something else to do so?
>- 
>-

### What kind of problems can we solve? (applications, use cases, examples)
>- 
>- 

***

## Option 5: Two Lidars and IMU
If Woodbot has two lidars and IMU:

### What kind of information can we get? 
>- 
>-

### What state can we estimate? Do we need something else to do so?
>- 
>-

### What kind of problems can we solve? (applications, use cases, examples)
>- 
>- 

***


## Option 6: GPS + IMU
If Woodbot has GPS and IMU:

### What kind of information can we get? 
>- 
>-

### What state can we estimate? Do we need something else to do so?
>- 
>-

### What kind of problems can we solve? (applications, use cases, examples)
>- 
>- 

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

