# Design Decisions: Sensors
## Objective
We like to select a state estimator that would be necessary for Woodbot to solve a particular problem. 
Depending on uncertainties we have in the system and requirements, our decisions will be determined.

### We like to 

- Narrow down state estimators that meet necessity and sufficiency
- Visit each option for what we need to implement them
- Consider what assumptions we need to make and what we can or cannot observe
- Reduce work loads for the later labs (by eliminating infeasible or inadequate estimators)
- Conduct design engineering decisions with proper supports

This will require you to fill out missing parts for full credits.

***

## List of estimators:
* Open loop estimators
* Close loop estimators
* Inverse of sensor measurements
* Low pass/Complementary filtering
* Kalman Filtering
* Particle Filtering

***

## Option 1: Open loop estimators
If Woodbot has an open loop estimator (Odometry, kinematics model):

### What do we need to implement these estimators?
#### Option 4 (encoders)
>- kinematics model given motor angular velocity
>- Encoder raw measurements
#### Option 5 (2 Lidars & IMU)
>- Inverse of lidar measurement model
>- Compass Inverse model
>- IMU raw measurements (Compass in x, y, gyro z)

### What kind of information can or cannot we get?
>- Robot states through predictions (kinematics model, inverse of sensor measurements)
>- No corrections of the states 
>- Once off, no way of correcting or knowing of the errors
>- No noise consideration

### What assumptions should we make?
>- No slip condition
>- Know initial state
>- Known accurate robot geometry
>- No disturbance in task space (someone pushing the robot, icy floor, hole, etc.)

***
## Option 2: Open loop estimators with filtering
If Woodbot has an open loop estimator (Odometry, kinematics model):

### What do we need to implement these estimators?
#### Option 4 (encoders)
>- kinematics model given motor angular velocity
>- Encoder raw measurements
>- Low pass filter
#### Option 5 (2 Lidars & IMU)
>- Inverse of lidar measurement model
>- Compass Inverse model
>- IMU raw measurements (Compass in x, y, gyro z)
>- Complementary filter 

### What kind of information can or cannot we get?
>- Robot states through predictions (kinematics model, inverse of sensor measurements)
>- No corrections of the states 
>- Once off, no way of correcting or knowing of the errors
>- Filter noises

### What assumptions should we make?
>- Same as Option 1

***
## Option 3: Closed loop estimators, Extended Kalman Filtering
If Woodbot has an open loop estimator (Odometry, kinematics model):

### What do we need to implement these estimators?
#### Option 5 (2 Lidars & IMU)
>- *Your answer here*
>- 
>- 
>- 

### What kind of information can or cannot we get?
>- *Your answer here*
>-
>-
>- 

### What assumptions should we make?
>- *Your answer here*
>- 
>- 
>- 

***
## Option 4: Closed loop estimators, Particle filtering
If Woodbot has an open loop estimator (Odometry, kinematics model):

### What do we need to implement these estimators?
#### Option 5 (2 Lidars & IMU)
>- *Your answer here*
>- 
>- 
>- 

### What kind of information can or cannot we get?
>- *Your answer here*
>-
>-
>- 

### What assumptions should we make?
>- *Your answer here*
>- 
>- 
>- 


***







# Design Decisions:
Now we like to narrow down and make decisions on which estimator we like to use.

### Requirements
>- Navigation in an arena (2D plane)
>- A map and an initial state are given 
>- Using affordable components and a microprocessor
>- Indoor

>- You cannot reset the robot during the operation (You cannot rescue the robot if localization fails)

## Experiments
We need to test our options so that we can conclude which option we should pick.

We like to run...
>1. Each estimator with zero inputs (stationary)
>2. Each estimator with a constant input (circle)
>3. Each estimator with a random input (your keyboard inputs)
>4. Each estimator with very low friction (friction coefficient = 0.05)
For 100 second.

## Experiments Outcome
### Option 1
>1. Stationary case
>   * *Your answer here*
>   * 
>2. Circular trajectory
>   * *Your answer here*
>   * 
>3. Random trajectory
>   * *Your answer here*
>   * 
>4. Low friction
>   * *Your answer here*
>   * 

### Option 3
>1. Stationary case
>   * *Your answer here*
>   * 
>2. Circular trajectory
>   * *Your answer here*
>   * 
>3. Random trajectory
>   * *Your answer here*
>   * 
>4. Low friction
>   * *Your answer here*
>   * 

### Option 4
>1. Stationary case
>   * *Your answer here*
>   * 
>2. Circular trajectory
>   * *Your answer here*
>   * 
>3. Random trajectory
>   * *Your answer here*
>   * 
>4. Low friction
>   * *Your answer here*
>   * 



## Decisions
>- Since we cannot reset the state estimator...
>- From the experiment outcome Option 1, Experiment 4...etc.
>- 
>- 


### My Conclusion: I go with Option ______ for the prototype

## Still Unknown, Things to be analyzed and decided later

>- We don't know whether our physics simulation captures all uncertainty in the system.
>- Although we can expect some kinds of uncertainties, but we don't know the magnitude of them, such as magnetic field induced by current in the circuit, lidar noises against black or too reflective surface, and wheel slipping, etc. 
>- We don't know how well the estimator would perform for longer duration than 100s or in a different environment 