import time

from rems.robots import RobotBase, RobotThread
import numpy as np


class WoodbotModel(RobotThread):
    '''

    '''

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.run.DT = 0.1      # Robot run frequency
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
        # saving the current input
        self.inpt.update(inpt)

        # get input, note they are in percent -100 to 100%
        inpt_np = self.inpt.ndarray()      # input values in numpy array
        inpt_nptall = self.inpt.ndtall()    # in numpy tall array
        wh_l = self.inpt.get('wh.l')    # or get specific
        wh_r = self.inpt.get('wh.r')

        x = self.state.get('x')
        y = self.state.get('y')
        th_z = self.state.get('th_z')
        d_th_z = self.state.get('d_th_z')

        state_np = self.state.ndarray()    # current state in numpy array
        state_nptall = self.state.ndtall()# numpay tall array

        dt = self.run.DT        # delta T, 0.1sec

        # getting dimensions, IDE may complain, but all variables in WoodbotDef are accessible
        W = self.dimension.get('W')
        d = self.dimension.get('d')
        R_env = self.dimension.get('R_env')
        max_vel = self.dimension.get('max_vel')

        # TODO: Implement your kinematics model

        ###############################
        # Your model equation here    #
        # next_state = f(state, inpt) #
        ###############################

        x_p = V_body * np.cos(th_z) * dt 
        y_p = V_body * np.sin(th_z) * dt
        th_p = th_z + (W_body * dt)

        next_state = np.array([x_p, y_p, th_p])


        # save next state
        # this will set the data based on positions
        self.state.update(next_state)



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
        max_vel = self.dimension.get('max_vel')

        # TODO: Implement your sensor model
        ###############################
        # Your model equation here    #
        # output = h(state, inpt)     #
        ###############################

        w_l = (wh_l/100) * max_vel
        w_r = (wh_r/100) * max_vel

        V_body = (d/4)(w_l + w_r)
        W_body = ((W*d)/4)(w_r + w_l)

        x = state[0]
        y = state[1]
        th = state[2]
        m = np.tan(th-90)

        if m < 0:
            n_xf = (2*m**2*x+2*m*y+np.sqrt((-2*m**2*x+2*m*y)**2-4*(1+m)*(m**2*x**2-2*m*y*x+y**2-R_env**2)))/(2*1+m**2)
        else:
            n_xf = (2*m**2*x+2*m*y-np.sqrt((-2*m**2*x+2*m*y)**2-4*(1+m)*(m**2*x**2-2*m*y*x+y**2-R_env**2)))/(2*1+m**2)
        n_yf = m * n_xf + y - m + x
        lidar_f = np.sqrt((n_xf-x)**2 + (n_yf-y)**2)

        if m < 0:
            n_xr = (2*m**2*x+2*m*y+np.sqrt((-2*m**2*x+2*m*y)**2-4*(1+m)*(m**2*x**2-2*m*y*x+y**2-R_env**2)))/(2*1+m**2)
        else:
            n_xr = (2*m**2*x+2*m*y-np.sqrt((-2*m**2*x+2*m*y)**2-4*(1+m)*(m**2*x**2-2*m*y*x+y**2-R_env**2)))/(2*1+m**2)
        n_yr = m * n_xr + y - m + x

        lidar_r = np.sqrt((n_xr-x)**2 + (n_yr-y)**2)


        output = np.array([lidar_f, lidar_r, np.cos(th),np.sin(th), W_body])

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



