/*
============================================================================
 Name : States
 Author : M.A.G.I.E Team
 Modified on: 2015-10-15
 Description : List the different general states of the robots
============================================================================
*/

#ifndef GENERALSTATES_H_
#define GENERALSTATES_H_

/*
 * General robot states
 */
enum GeneralStates
{
	Wander = 0,
	TowardPlayer,
	Play,
	Stay,
	Exit
};

#endif /* GENERALSTATES_H_ */
