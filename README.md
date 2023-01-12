# ECE Capstone Lab Materials
***
## About
This repository contains all lab materials necessary for our lab series. 

You will work with your partner to complete each lab. 


## Lab Materials and Submissions

- You can find each lab instructions as lab1.md, etc.
- Each lab folder contains necessary materials such as codes and simulation files.
- You will push your solutions for submissions. 
- You need to submit a link to your forked repository on Canvas for grading purposes. 
- There is no formal report for these labs.



***

## Lab Overview

Throughout this lab series, you will conduct design decisions to select set of hardware and software for our prototype robot, Woodbot, a differential drive 2-wheel car robot.
Then we evaluate our selections and revisit/iterate the decisions. 

### Lab 1: System Modeling
- [ ] Mathematical modeling and analysis of Woodbot
- [ ] Python implementation of the Woodbot model
- [ ] Design decisions on our sensor selections for Woodbot

### Lab 2: Simulation
- [ ] Implementing physics simulation of Woodbot using Webots
- [ ] Design decisions on our state estimator for Woodbot

### Lab 3: Hardware
- [ ] Assembly and soldering of Woodbot hardware
- [ ] Design decisions on the Woodbot support structure design

### Lab 4: Analysis
- [ ] Comparison among the mathematical model, physics simulation and hardware
- [ ] Design experiments to compare them to conduct and revisit our design decisions


## Design Decisions

Each step helps us to decide the different parts of the final system design.
This process help engineers to avoid time-consuming and expensive mistakes.

We don't want to realize that your design choices were in adequate or infeasible after you made hardware prototype. We can use mathematical and computational tools to analyze, test and evaluate each decision. 

However, some of the decisions cannot be done merely with math or simulation because these tools cannot capture the all uncertainties in the system.


### We want to:
- Avoid time consuming and expensive mistakes (It is your time and fund!)
- Support your decisions with proper references, math, simulation, experiments or analysis.
- Use appropriate tools to conduct design decisions on a selected component
- Consider edge cases to expect or find out where your system breaks or doesn't break
- Evaluate, revisit, and reiterate design decisions to improve and finalize them

### We DON'T want to: 
- Pick up random/arbitrary design decisions and build hardware, then figure out it won't work
- And realize you could have avoided such mistakes with a simple math or Google search
- Fabricate a perfect condition/environment/setup so your system works perfectly
- Not re-visit or re-iterate your decisions

As a note, even if you do your best, you cannot foresee all uncertainties. 

***

## Getting started

- [ ] Install and prepare [IDE](https://www.jetbrains.com/products/compare/?product=pycharm&product=pycharm-ce) for Python 3.8
- [ ] Fork this repository
- [ ] Then git clone 
- [ ] Install all requirements with
```shell
pip install -r requirements.txt
```

***
## File Structure


```
kinematics
│   README.md
│   requirements.txt              (Pip Dependencies)   
│
└───Lab1
└───Lab2
└───Lab3
└───Lab4
    
```

