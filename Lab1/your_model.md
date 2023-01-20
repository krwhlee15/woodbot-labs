# Mathematical Model for Differential Drive Robot

## System Definition

![Hardware](images/Woodbot.jpg)
Figure 1:Woodbot Hardware for this lab series.


In this lab, we formulates a mathematical model for Woodbot in Fig. 2, a differential drive 2-wheel robot. 

![dimensions](images/size_def.png)
Figure 2: The Woodbot schematic and dimensions.


The robot physical dimensions are defined as in Fig. 2.

## Kinematics Model
### State
```
Your state definitions here.
```


### Kinematics Model
The 4 patterns of differential drive robot forward and tun motions are illustrated as following.
![robot](images/differential_drive.png)

The relationship between wheel angular velocity and wheel tangential velocity is illustrated as follows.
![wheel](images/wheel.png)

Thus, under no slip condition, the robot translational velocity and angular velocity can be described as:

> $`V_{body} = 0.5*(\frac{d}{2}*w_{left} + \frac{d}{2}*w_{right})`$
> 
> $`\Omega_{body} = \frac{W}{2} * (w_{right}-w_{left})`$
> 
> Note: for GitLab to show math you need to use 
```
$` latex math format `$ 
```
> You can use tool like [mathpix](https://mathpix.com/), which let you scan typed or hand written math into format
> 
> You can alternatively paste your math in images, such as:
```![my math scan](path/to/image.jpg)```

We can illustrate Markovian system the robot next state given the current state and input: 
![state](images/state_change.png)

Which now can be expressed in a 1st order system model (kinematics model) as:

> Your kinematics model here.
> 
> $`X' = f(X, U)`$
> 
> You can alternatively paste your math in images, such as:
```![my math scan](path/to/image.jpg)```




### Sensor Model
![lidar](images/Environment.png)

> Your lidar sensor model here.
> 
> You can alternatively paste your math in images, such as:
```![my math scan](path/to/image.jpg)```

![compass](images/compass.png)

> Your compass sensor model here.
> 
> You can alternatively paste your math in images, such as:
```![my math scan](path/to/image.jpg)```

