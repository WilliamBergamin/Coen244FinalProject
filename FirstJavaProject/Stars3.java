import javax.swing.*;
import java.awt.*;

public class Stars3 extends JFrame{

    //choose what origine you want
    public static final boolean pos1 = true;             // position of graph with center of gravity at origine
    public static final boolean pos2 = false;            // position of graph with big star at origine
    public static final boolean pos3 = false;            // position of graph with small star at origine

    //declare and initialize variables
    public static final double mA = 5.0;                //Mass of star A in Solar Mass units
    public static final double rA = 2.0;                //Distance from star A to center of gravity in Astronomical Units (A.U.)
    public static final double periodT = 30.0;          //Total period of rotation with axis centered at star A in years
    public static final double dt = 0.01*periodT;       //time step for each fram of animation
    public static double rB;                			//Distance from star B to center of gravity in Astronomical Units (A.U.)
    public static double semiMaj;               		//Semi-major axis of total orbit with axis centered at star A
    public static double vA;			    			//Velocity of star A in km/s
    public static double vB;                			//Velocity of star B in km/s
    public static double vTot;             			    //Total velocity of star A and star B km/s
    public static double angVelA;               		//angular velocity of star A in rad/s
    public static double angVelB;               		//angular velocity of star B in rad/s
    public static double t;								//time

    // static variables for the drawing
    public static final int WINDOW_SIZE = 800;          // size of the window
    public static final int NGRID = 2;                  // number of lines that we want
    public static final int DX = WINDOW_SIZE/NGRID;     // distance in x from the edg for the line
    public static final int DY = WINDOW_SIZE/NGRID;     // distance in y from the edg for the line
    public static final int StarA = 15;                 // size of the biggest star
    public static final int StarB = 10;                 // size of the smallest star

    public static void main(String[] args) {

        double mB;     //Mass of star B in Solar Mass units

        mB = transcendental(mA, rA, periodT);   //mB equals value returned by transcendental method

        System.out.println("Mass of star B in Solar Masses. is:  " + mB);

        //calculate semi major axis

        semiMaj = rA * (1 + (mA / mB));

        //Calculate velocity of each star

        vTot = ((2.0 * Math.PI * semiMaj) / periodT);
        vA = vTot / ((mA / mB) + 1);
        vB = vTot - vA;

        // rb
        rB = semiMaj - rA;


        //angular velocities of star A and B
        angVelA = vA / rA;
        angVelB = vB / rB;

        // create the envirement

        Stars3 environment = new Stars3();
        environment.setVisible(true);
        {
            // Recalculate position of planet
            boolean step = true;
            while  (step == true)
            {
                t+=dt;

                environment.repaint();

                // Pause a bit
                try {
                    Thread.sleep(140);
                } catch (InterruptedException ex) {
                    Thread.currentThread().interrupt();
                    System.out.println("Problem");
                }

                step = true;
            }
        }
    } //end main

    /*
    painting th Window important, establishing its size and color
    */
    public Stars3()
    {
        super("binary star system");
        setSize(WINDOW_SIZE,WINDOW_SIZE);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        getContentPane().setBackground(Color.black);

    }

    /*
     The paint() method draws the environment and stars current position.
    */
    public void paint(Graphics g)
    {
        if (pos1 == true) {
            super.paint(g);

            // Draw grid
            g.setColor(Color.white);
            for (int i = 0; i < NGRID; i++) {
                g.drawLine(i * DX, 0, i * DX, WINDOW_SIZE);
            }
            for (int j = 0; j < NGRID; j++) {
                g.drawLine(0, j * DY, WINDOW_SIZE, j * DY);
            }


            // Draw star 1
            g.setColor(Color.red);
            g.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 5));
            int XposStara = (int) positionx(t, angVelA, ((-rA) * 15.0)) + (WINDOW_SIZE / 2); //+ (int)(centerMassX(t, rA*15, angVelA)
            int YposStara = (int) positiony(t, angVelA, ((-rA) * 15.0)) + (WINDOW_SIZE / 2); //(int)(centerMassY(t, rA*15, angVelA)
            int widthStara = StarA;
            int hightStara = StarA;
            g.fillOval(XposStara, YposStara, widthStara, hightStara); //placing size and pposition of oval (int x, int y, int width, int lenght

            // Draw star 2
            g.setColor(Color.white);
            g.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 5));
            int XposStarb = (int) positionx(t, angVelB, rB * 15.0) + (WINDOW_SIZE / 2); //+ (int)(centerMassX(t, rA*15, angVelA)
            int YposStarb = (int) positiony(t, angVelB, rB * 15.0) + (WINDOW_SIZE / 2); //+ (int)(centerMassY(t, rA*15, angVelA)
            int widthStarb = StarB;
            int hightStarb = StarB;
            g.fillOval(XposStarb, YposStarb, widthStarb, hightStarb); //g.draOval (int x, int y, int width, int lenght)

            System.out.println("YposStarA " + YposStara + "   YposStarA " + YposStara + "    XposStarB " + XposStarb + "   YposStarB " + YposStarb);
        }

        if (pos2 == true) {
            super.paint(g);


            // Draw star 1
            g.setColor(Color.red);
            g.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 5));
            int XposStara = (WINDOW_SIZE / 2); //+ (int)(centerMassX(t, rA*15, angVelA)
            int YposStara = (WINDOW_SIZE / 2); //(int)(centerMassY(t, rA*15, angVelA)
            int widthStara = StarA;
            int hightStara = StarA;
            g.fillOval(XposStara, YposStara, widthStara, hightStara); //placing size and pposition of oval (int x, int y, int width, int lenght

            // Draw star 2
            g.setColor(Color.white);
            g.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 5));
            int XposStarb = (int) positionx(t, angVelB, rB * 15.0) + (int) positionx(t, angVelA, (rA * 15.0)) + (WINDOW_SIZE / 2); //+ (int)(centerMassX(t, rA*15, angVelA)
            int YposStarb = (int) positiony(t, angVelB, rB * 15.0) + (int) positiony(t, angVelA, (rA * 15.0)) + (WINDOW_SIZE / 2); //+ (int)(centerMassY(t, rA*15, angVelA)
            int widthStarb = StarB;
            int hightStarb = StarB;
            g.fillOval(XposStarb, YposStarb, widthStarb, hightStarb); //g.draOval (int x, int y, int width, int lenght)


            // Draw grid
            g.setColor(Color.white);
            for (int i = 0; i < NGRID; i++) {
                g.drawLine(i * ((int) positionx(t, angVelA, (rA * 15.0)) + (WINDOW_SIZE / 2)), 0, i * ((int) positionx(t, angVelA, (rA * 15.0)) + (WINDOW_SIZE / 2)), WINDOW_SIZE);
            }
            for (int j = 0; j < NGRID; j++) {
                g.drawLine(0, j * ((int) positiony(t, angVelA, (rA * 15.0)) + (WINDOW_SIZE / 2)), WINDOW_SIZE, j * ((int) positiony(t, angVelA, (rA * 15.0)) + (WINDOW_SIZE / 2)));
            }

            System.out.println("YposStarA " + YposStara + "   YposStarA " + YposStara + "    XposStarB " + XposStarb + "   YposStarB " + YposStarb);
        }

        if (pos3 == true) {
            super.paint(g);


            // Draw star 1
            g.setColor(Color.red);
            g.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 5));
            int XposStara = (int) positionx(t, angVelB, ((-rB) * 15.0)) + (int) positionx(t, angVelA, ((-rA) * 15.0)) + (WINDOW_SIZE / 2); //+ (int)(centerMassX(t, rA*15, angVelA)
            int YposStara = (int) positiony(t, angVelB, ((-rB) * 15.0)) + (int) positiony(t, angVelA, ((-rA) * 15.0)) + (WINDOW_SIZE / 2); //(int)(centerMassY(t, rA*15, angVelA)
            int widthStara = StarA;
            int hightStara = StarA;
            g.fillOval(XposStara, YposStara, widthStara, hightStara); //placing size and pposition of oval (int x, int y, int width, int lenght

            // Draw star 2
            g.setColor(Color.white);
            g.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 5));
            int XposStarb = (WINDOW_SIZE / 2); //+ (int)(centerMassX(t, rA*15, angVelA)
            int YposStarb = (WINDOW_SIZE / 2); //+ (int)(centerMassY(t, rA*15, angVelA)
            int widthStarb = StarB;
            int hightStarb = StarB;
            g.fillOval(XposStarb, YposStarb, widthStarb, hightStarb); //g.draOval (int x, int y, int width, int lenght)


            // Draw grid
            g.setColor(Color.white);
            for (int i = 0; i < NGRID; i++) {
                g.drawLine(i * ((int) positionx(t, angVelB, ((-rB) * 15.0)) + (WINDOW_SIZE / 2)), 0, i * ((int) positionx(t, angVelB, ((-rB) * 15.0)) + (WINDOW_SIZE / 2)), WINDOW_SIZE);
            }
            for (int j = 0; j < NGRID; j++) {
                g.drawLine(0, j * ((int) positiony(t, angVelB, ((-rB) * 15.0)) + (WINDOW_SIZE / 2)), WINDOW_SIZE, j * ((int) positiony(t, angVelB, ((-rB) * 15.0)) + (WINDOW_SIZE / 2)));
            }

            System.out.println("YposStarA " + YposStara + "   YposStarA " + YposStara + "    XposStarB " + XposStarb + "   YposStarB " + YposStarb);
        }

    } // end paint


    public static double positionx (double t, double angVel, double r)
    {
        double dTheta;  //Change in angular position of starA
        double xStar;   // position of star in x

        dTheta = angVel*(t);
        xStar  = Math.cos(dTheta)*r;

        return xStar;
    } // end positionx


    public static double positiony (double t, double angVel, double r)
    {
        double dTheta;  //Change in angular position of starA
        double yStar;   // position of star in y

        dTheta = angVel*(t);
        yStar  = Math.sin(dTheta)*r;

        return yStar;
    } // end positiony


    public static double transcendental(double mA, double rA, double periodT)
    {
        int g = 100000;

        double[] mB = new double[g];
        double mBValue = 0.0;

        mB[0] = 15.0;
        mB[1] = Math.pow((rA*((mB[0] + mA)/periodT)),(2.0/3.0));
        int i = 2;

        while((mB[i] - mB[i-1]) <= 0.01 && i<16)
        {
            mB[i] = Math.pow((rA*((mB[i-1] + mA)/periodT)),(2.0/3.0));

            mBValue = mB[i];

            i++;
            System.out.println(mBValue);
        }
        return mBValue;
    } //end transendental


}// End class stars3