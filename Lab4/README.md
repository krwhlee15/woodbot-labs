# Lab 4: Comparisons and Design Decisions

## Pre Requirements:
- Your kinematics model and python code
- Functional Webots
- Functional Woodbot Hardware
- Arduino IDE with necessary libraries

## Objectives
- Identify which of analytical model, physics simulation and hardware is appropriate for specific design decisions
- Conduct experiments to compare and identify uncertainties in the system
- Conduct design decisions on Woodbot system designs
- Revisit Lab 1-3 design decisions 

## *Why we need to use models, tools, and hardware?*
* Each one of them has advantage and drawbacks
* Some of them do not capture all uncertainties
* Hardware is too uncertain sometimes
* For unit test, debugging, i.e.
    * Test a controller using a math model
    * Test an algorithm using a math model
    * Test an algorithm using a physics simulations
    * Integrating the controller and the algorithm in a physics simulation
    * Build and test hardware to make sure they function as expected
    * Then include the tested controllers and algorithms

## Design Decisions
1. Decide the Center of Mass (CoM) allocation
2. Design Trajectory
3. Tail Design

## Notes
- You need to do design decisions based on either model, simulation, or hardware
- But still run others for comparisons at least once
- For the math model, you can do realtime=False and run as fast as possible

## Wifi
Connect to woodbot-wifi
- password is goodwoodbot
- in firmware, change hostname something unique
- flash the code and open serial monitor to see your woodbot ip address
- You need to replace your ip in run_woodbot.py etc.

## CoM Allocation
- Total weight of the actual hardware is 0.12kg
- The positive x is pointing toward the front of Woodbot (0 at the front)
- Assume that the CoM in the z direction is about on the surface of PCB
- The hardware is symmetric
### How the robot will be affected by the change of CoM?
- What could be expected behaviors of moving the CoM to the front in the x direction 
> - Your answer here
> - 

- What could be expected consequences due to such behaviors? How it can affect the performance of Woodbot?
> - Your answer here
> -

### Experiments
- Try CoM of x =-0.04, -0.03, -0.02, -0.015 at least
- You cannot modify hardware
- Create appropriate trajectories to best determine the effect

### Which one do you use to make the decisions, math model, physics simulation, hardware?
> - Your answer

#### Why?
> - The math model is...
> - The physics simulation is...
> - The hardware is...

### Results and Discussions
> - Tell us your observations.
> - How change in the parameter affected the system?
> - Show some figures/screenshots
> 
### Design Decisions
Given your results, what is the appropriate range of CoM? 
If we are to modify the hardware what and how do you change based on the result?
>- 
>- 

******

## Design Trajectory
- Design a trajectory that makes a triangle 
- modify the cvs file to create input references
- the robot starts from the origin, but the robot can move to your 'start point' first
- you can only test hardware once in the field due to limited availability

### how the flow chart of this trajectory looks like?
- list or show us the flow of the trajectory. You can do like the example or write a chart and attach here.
- example: making a circle

1. Init state
2. Move forward by 0.017m (0.25s)
3. Spin right 90 degree (0.317s)
4. Run Left at 100% and right at 50 % for x sec....

> - Your answer here
> - 


### Experiments
- Write a reference input using the csv example
- You only run hardware once in the field

### Which one do you use to design the trajectory first, math model, physics simulation, hardware?
> - Your answer

#### Why?
> - The math model is...
> - The physics simulation is...
> - The hardware is...

### Results and Discussions
> - Tell us your observations.
> - Does the same trajectory gives you triangle for all model, simulation and hardware?
> - Show some figures/screenshots
> 
### Design Decisions
Given your results, how can you make the results more consistent across model, simulation and hardware?
If we are to modify the hardware what and how do you change based on the result?
>- 
>- 

******

## Tail Design
- Evaluate the pointy and circular tail design in two different surfaces

### What is expected outcome based on the tail design, environment and motion?
> - Your answer here
> #### With a clean epoxy surface
> - When moving forward the pointy tail...
> - When moving forward the circular tail...
> - When turning the pointy tail...
> - When turning forward the circular tail...
> - ....
> #### With green carpet
> - When moving forward the pointy tail...
> - When moving forward the circular tail...
> - When turning the pointy tail...
> - When turning forward the circular tail...
> - ....

### Experiments
- Try two tails in two different environments
- You can separately run model and webots from hardware later as long as you save the trajectory

### Which one do you use to make the decisions, math model, physics simulation, hardware?
> - Your answer

#### Why?
> - The math model is...
> - The physics simulation is...
> - The hardware is...

### Results and Discussions
> - Tell us your observations.
> - How change in the tail affected the system?
> - How did they sound?
> - Show some figures/screenshots
> 
### Design Decisions
Given your results, what is your design decisions? 
If we are to modify the hardware what and how do you change based on the result?
>- 
>- 
