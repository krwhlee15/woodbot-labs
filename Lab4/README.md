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
> - When the CoM is towards the front in the x direction, it could be more stable.
> - It will have less friction on the wheels but more friction on the tail.

- What could be expected consequences due to such behaviors? How it can affect the performance of Woodbot?
> - It would be less stable
> - It may drag more
> - If the center of mass is really huge, then it may flip over the robot itself.

### Experiments
- Try CoM of x =-0.04, -0.03, -0.02, -0.015 at least
- You cannot modify hardware
- Create appropriate trajectories to best determine the effect

### Which one do you use to make the decisions, math model, physics simulation, hardware?
> - Physics Simulation

#### Why?
> - The math model is decent, but it is not as accurate as the physics simulation. It may give an idealistic set of data, but it is not as accurate.
> - The physics simulation is the best choice because it is the most realistic to our situation and gives us the most reliable data which we could use.
> - The hardware would be the best if we could measure the CoM for the hardware. However, we cannot find where the center of mass is. Also, even if we could find the center of mass, we could not figure out how to adjust the center of mass. Also, the battery makes the CoM variable.

### Results and Discussions
> - When we had the CoM too low, the simulation was extremely unsteady and wiggled a lot. There was too much friction on the tip which caused  a lot of issues.
> - When the CoM was too high, the shape was ok, but the lengths were way too high and it ran too long.
> - We discovered the closest to perfect design was CoM with CoM of -0.02.
> - It still was not completely perfect, but it was very close to what we want.
### Design Decisions
Given your results, what is the appropriate range of CoM? 
If we are to modify the hardware what and how do you change based on the result?
> - We discovered the closest to perfect design was CoM with CoM of -0.02.
> - It still was not completely perfect, but it was very close to what we want.
> - It is hard to change the hardware, so I would not change the hardware. However, if I did change the hardware I think it is hard to be exact, so I would rather have a CoM that is closer to 0 than further from 0. If the magnitude was too high, it caused more issues than if it was smaller, so I would try to put the center of mass towards that location.

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

> - Init state
> - Move forward for 1.5 seconds
> - Spin right 120 degrees(0.55s)
> - Move forward for 1.5 seconds
> - Spin right 120 degrees(0.55s)


### Experiments
- Write a reference input using the csv example
- You only run hardware once in the field
> - 

### Which one do you use to design the trajectory first, math model, physics simulation, hardware?
> - Physics simulation

#### Why?
> - The math model is not ideal for real tests because although it is idealistic
> - The physics simulation is better for real tests because it awknowledges that there are discrepancies with the data
> - The hardware is hard to get exact readings from and can be subject to random variables of chane

### Results and Discussions
> - Tell us your observations.
> - Does the same trajectory gives you triangle for all model, simulation and hardware?
> - Show some figures/screenshots
> - Although there are some discrepancies, a general triangle shape is made. Some errors can occur because the wheels do not turn enough. We can account for this by turning a little bit more. Also, it may cross over itself, which we think is ok because it still makes a triangle shape.
### Design Decisions
Given your results, how can you make the results more consistent across model, simulation and hardware?
If we are to modify the hardware what and how do you change based on the result?
>- We can have everything run slowly and for a short period of time so that any random changes are small
>- However, this may make the results not super helpful because of how small the sample size is.
>- We can also change hardware designs to help improve stability.

******

## Tail Design
- Evaluate the pointy and circular tail design in two different surfaces

### What is expected outcome based on the tail design, environment and motion?
> - Your answer here
> #### With a clean epoxy surface
> - When moving forward the pointy tail works well with little to no significant discrepancies in predicted motion.
> - When moving forward the circular tail works well with little to no significant discrepancies in predicted motion.
> - When turning the pointy tail works well for the most part, but seems more susceptible to get snagged onto things
> - When turning forward the circular tail is more smooth and doesn't really get caught on things
> - ....
> #### With green carpet
> - When moving forward the pointy tail works well as predicted.
> - When moving forward the circular tail works well as predicted.
> - When turning the pointy tail it got snagged on a lot of things because of the uneven texture of the carpet. It wasn't a big deal, but it was worth mentioning
> - When turning forward the circular tail it seemed also to get slightly caught on the carpet but barely

### Experiments
- Try two tails in two different environments
- You can separately run model and webots from hardware later as long as you save the trajectory

### Which one do you use to make the decisions, math model, physics simulation, hardware?
> - The physics simulation allows us to change the tail design

#### Why?
> - The math model is hard to use to simulate the capabilites for tails.
> - The physics simulation has the capabilities of knowing how the machine will run.
> - The hardware requires too many resources and is hard to measure.

### Results and Discussions
> - Tell us your observations.
> - How change in the tail affected the system?
> - How did they sound?
> - Show some figures/screenshots
> - The changes in tails did not really have a significant change in the results of the experiment. The pointy tail had a little more drag, which made it steadier but also moved less than the other tails.
### Design Decisions
Given your results, what is your design decisions? 
If we are to modify the hardware what and how do you change based on the result?
>- We want to use the round tail
>- The round tail gets snagged on things too easily
>- The pointy tail gives enough stability because of the drag of the material
>- The pointy tail achieves all we want to accomplish
