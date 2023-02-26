# Design Decisions: Sensors
## Objective
We like to select a set of sensors that would be necessary for Woodbot to solve a particular problem. 
Depending on sets of sensors we pick, we can do state estimations which maybe necessary for our applications.

### We like to 

- Narrow down hardware design 
- Visit each option and conduct experiments
- Conduct design engineering decisions with proper supports

This will require you to fill out highlighted parts for full credits.

***
## Options:
* Option 1: pointy tail
* Option 2: circular tail
* Option 3: no tail

## Experiments:
Using las week codes, modify that so we can run the servos to do the followings:

- back and forth for 1s
- turning 
- spining

on different surfaces

## Results
### How well can each option run straight?
> - There are no significant differences when they robot is running straight
> - It seems as if with no tail the robot performs marginally better, but there is no significant difference
> - All options seem to turn the robot even when it is supposed to be going straight

### how well can each option turns?
> - The robot turns equally as well with the pointy and circular tail
> - With no tail, it seems as if the robot doesn't turn as much

### is there any edge case for each option?
> - There may be a little bit of drag with no tail when the robot is performing slower
> - When the robot is operating fast, there is virtually no difference.

### how each options can affect sensor measurements?
1. Lidar
>* Option 1: With no tail, lidar measurements are off because everything is tilted.
>* Option 2: There is no obstruction with the triangular tail, so lidar works correctly.
>* Option 3: There is no obstruction with the circular tail, so lidar works correclty

2. IMU

>* Option 1: With no tail, everytning is tilted, so IMU readings are off
>* Option 2: The triangular tail provides the most straight data
>* Option 3: The circular tail seems slightly tilted, but not significant

## Uncertainties
### Was there any uncertainty that we observed with hardware, but not observed in Webots or model?
> - The robot wheels are not put on perfectly, so there is a discrepancy in how it drives(drives at a tilt)
> 

### Can we observe the uncertainties on-board?
> - With IMU measurements, we should be able to measure and correct the uncertainties

### Do you think we need more sensors? If so, what kind?
> - With the current goals for the project, it does not seem as if we need more sensors for the robot to drive correctly
> - However, with the sensors we need to program more enviromental data.


### Requirements
>- Navigation in an arena (2D plane)
>- A map and an initial state are given
>- Using affordable components and a microprocessor
>- Indoor

### Decisions
which options are good based on the results?
Are they good
>- The options that are best based on the results are the triangular tail and the circular tail


#### My Conclusion: I go with Option 2 (triangular tail)


### Still Unknown, Things to be analyzed and decided later
>- How to account for discrepancies of the wheels.

