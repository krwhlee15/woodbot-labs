from rems import Operator, SimConfig
from rems.inputs import FileCsvInput, KeyboardInput
from rems.outputs import FileCsvOutput, AnimationOutput
from rems.utils import time_str, rems_update
from rems.device.webots import WebotsBinder
# Woodbot import
from Lab1.WoodbotDef import WoodbotDef


OUTPUT_PATH = 'run_outputs/'
WEBOTS_FILE_PATH = OUTPUT_PATH + 'Webots' + time_str() # this will be like: Model_current_data_time

# if you want to use pre defined trajectory
USE_DEMO_TRAJECTORY = False


# a nice function to automatically update the dependency
# rems_update()

# REMS robot operator
# this take care lower level operations
o = Operator(debug_mode=True)


if USE_DEMO_TRAJECTORY:
    i = FileCsvInput('run_outputs/webots_test_run.csv')
else:
    # Using  keyboard input (control Woodbot with arrow keys)
    # up: straight (100%, 100%), down: backward (-100, -100)
    # right: (100, 0), left: (0, 100)
    # up & right: (100, 50), up & left: (50, 100)
    # pageup: (-100, 100), pagedown: (100, -100)
    i = KeyboardInput()

#  set input
o.set_input(i)

# Setup robot with output you want
# robot def -> robot universal definitions such as state and input
# robot -> is actual implemntation (your kinematics code)
# outputs -> OutputSystem that show/record the data
# FileCsvOutput -> save CSV file at the end of run with all inpt, state, output. (You can feed this file to FileCsvInput)
# AnimationOutput -> Show the robot states realtime and save the video of it at the end.

robot = o.add_robot(robot_def=WoodbotDef, robot=WebotsBinder,
                    outputs=(FileCsvOutput(WEBOTS_FILE_PATH + '.csv'),
                             AnimationOutput(WEBOTS_FILE_PATH + '.gif')))


# run the robot for 10sec with dt = 0.1.
# realtime=True, so it'll take 10sec to finish, False will run as fast as possible
# start_time will let you start t=n. i.e. you want to run input file from t=5sec
# run_speed multiply the realtime run speed. i.e. you want to debug the robot by running slow
o.run(SimConfig(max_duration=100, dt=0.1, realtime=False, start_time=0, run_speed=1))

