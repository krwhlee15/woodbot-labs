import time

from rems.robots import RobotBase, RobotThread
import numpy as np


class WoodbotModel(RobotThread):
    '''

    '''

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.run.DT = 0.05      # Robot run frequency
        self.run.name = 'Model' # robot name

    def drive(self, inpt, timestamp):
        '''
        This is where we drive the robot.
        Robot drive function. Called at every time step.
        Receive inout and timestamp and then "drive" the robot

        :param inpt: Dictionary like object
        :param timestamp: float world timestamp
        :return: None
        '''

        inpt = self.inpt.ndarray()      # input values in numpy array
        state = self.state.ndarray()    # current state in numpy array

        # getting dimensions
        W = self.dimension.get('W')
        d = self.dimension.get('d')
        R_env = self.dimension.get('R_env')

        # TODO: Implement your kinematics model

        ###############################
        # Your model equation here    #
        # next_state = f(state, inpt) #
        ###############################

        next_state = np.array([0, 0, 0, 0])

        # save next state
        # this will set the data based on positions
        self.state.update(next_state)

        # saving the current input (this is not necessary because it happens automatically)
        self.inpt.update(inpt)


    def sense(self):
        '''
        Sensor implementation
        Called at every timestep
        :return: output values (iterative)
        '''

        inpt = self.inpt.ndarray()  # input values in numpy array
        state = self.state.ndarray()  # current state in numpy array

        # getting dimensions
        W = self.dimension.get('W')
        d = self.dimension.get('d')
        R_env = self.dimension.get('R_env')


        # TODO: Implement your sensor model
        ###############################
        # Your model equation here    #
        # output = h(state, inpt)     #
        ###############################

        output = np.array([0, 0, 0, 0, 0])
        self.outpt.update(output)
        return self.outpt

    def observe_state(self):
        '''
        This will return state of the robot at a time step
        :return: state (iterative)
        '''

        # here you have nothing to do because our 'drive' indeed updates the state
        return self.state



