from rems import Operator, SimConfig
from rems.inputs import FileCsvInput, KeyboardInput
from rems.outputs import FileCsvOutput, AnimationOutput
from rems.utils import time_str, rems_update
# Woodbot import
from WoodbotDef import WoodbotDef
from WoodbotModel import WoodbotModel


OUTPUT_PATH = 'run_outputs/'
FILE_PATH = OUTPUT_PATH + 'Model' + time_str() # this will be like: Model_current_data_time

rems_update()

o = Operator(debug_mode=True)

#
# i = FileCsvInput('path/to/inpt.csv')
# Using  keyboard input (control Woodbot with arrow keys)
i = KeyboardInput()

#  set input
o.set_input(i)

# Setup robot with output you want
# robot def -> robot universal definitions such as state and input
# robot -> is actual implemntation (your kinematics code)
# outputs -> OutputSystem that show/record the data
# FileCsvOutput -> save CSV file at the end of run with all inpt, state, output. (You can feed this file to FileCsvInput)
# AnimationOutput -> Show the robot states realtime and save the video of it at the end.

robot = o.add_robot(robot_def=WoodbotDef, robot=WoodbotModel,
                    outputs=(FileCsvOutput(FILE_PATH + '.csv'),
                             AnimationOutput(FILE_PATH + '.avi')))




# run the robot for 10sec with dt = 0.1.
# realtime=True, so it'll take 10sec to finish, False will run as fast as possible
# start_time will let you start t=n. i.e. you want to run input file from t=5sec
# run_speed multiply the realtime run speed. i.e. you want to debug the robot by running slow
o.run(SimConfig(max_duration=10, dt=0.1, realtime=True, start_time=0, run_speed=1))
 
