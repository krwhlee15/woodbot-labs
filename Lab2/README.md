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
## Merge command
```bash
git remote add upstream https://git.capstone.uclalemur.com/staff/woodbot-labs
git fetch upstream
git merge upstream/main
# If you get unrelated history error, you can force merging with
git merge upstream/main −−allow−unrelated−histories
```


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
>- Inverse of Lidar measurement model
>- Compass Inverse model
>- IMU raw measurements
>- Error implementation with filter
>- Update step basd on measurements


### What kind of information can or cannot we get?
>- Estimate of state
>- We can get a correction of the states
>- Based on errors, a fix of state
>- Filter noises and potential errors

### What assumptions should we make?
>- Known initial state
>- No slip state
>- No disturbance
>- Known robot dimensions

***
## **OPTIONAL** (Option 4: Closed loop estimators, Particle filtering)
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
>1. The estimator with a constant input (circle)
>2. The estimator with repeated inputs (straight back and forth)
>3. The estimator with random inputs (your keyboard inputs)
For 10 second.

### Instructions
> * set Webots worldInfo >> randomSeed to -1 
> * Save the world
> * Use run_webots_model.py to run both webots and your kinematics model from lab 1.
> * Your kinematics model can be considered as your open-loop estimator (Option 1), which assume no noise at all and only based on joint velocities
> * Webots states are in this case 'real robot' with noises. 

> 1. Use keyboard to create trajectories for each case
> 2. Use the csv file to run the robot
>    * set USE_DEMO_TRAJECTORY = True
>    * change file name appropriately for FileCsvInput('file_path.csv')
> 3. Run each case three times. 
> 4. Compare your kinematics and webots (x, y) states
>   * what is the error between these two trajectories? Use [mean absolute percentage errors](https://www.statology.org/mape-excel/#:~:text=Recall%20that%20the%20absolute%20percent,percent%20error%20for%20each%20row.)
>   * what is the error between two trajectories from the same robots
>   * Plot figures and attach here.
> 5. Compare your magnetometer measurements in the same way
> 6. Optional: Compare your lidar measurements in the same way


## Experiments Outcome
>1. Circular trajectory
>   * The models have state error of 15.7 and magnometer errors of 19.3.
>   * The webots have state errors of 22.61 and magnometer errors of 6.72.
>2. back and forth trajectory
>   * The models have state error of 13.2 and magnometer errors of 19.3.
>   * The webots have state errors of 22.61 and magnometer errors of 6.72.
>3. Random trajectory
>   * *Your answer here*
>   * 



## Decisions
>- Since we cannot reset the state estimator...
>- From the experiment outcome 3...etc. 
>- 
>- 


### My Conclusion: I go with Option ______ for the prototype

## Still Unknown, Things to be analyzed and decided later

>- We don't know whether our physics simulation captures all uncertainty in the system.
>- Although we can expect some kinds of uncertainties, but we don't know the magnitude of them, such as magnetic field induced by current in the circuit, lidar noises against black or too reflective surface, and wheel slipping, etc. 
>- We don't know how well the estimator would perform for longer duration than 100s or in a different environment 
