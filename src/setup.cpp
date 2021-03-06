#define ROBOT_COUNT 210
#define NUM_IN_GROUP 70
#define NUM_OF_GROUP 3
#define ROBOT_SPACING 40

#define ARENA_WIDTH (32*32 + 33*ROBOT_SPACING) * 2
#define ARENA_HEIGHT (32*32 + 33*ROBOT_SPACING) * 2

#define LIGHT_CENTER_X ARENA_WIDTH / 2
#define LIGHT_CENTER_Y ARENA_HEIGHT / 2

#define SIMULATION_TIME 180 //in seconds

int iteration = 0;


// function to check if randomly generated positions are in collision
bool collision(float x, float y, float pos_list[ROBOT_COUNT][4], int limit) {
	for (int i = 0; i < limit; i++) {
		float existing_x = pos_list[i][0];
		float existing_y = pos_list[i][1];
		float dist = sqrt(pow(x - existing_x, 2) + pow(y - existing_y, 2));
		if (dist <= radius * 2) {
			return true;
		}
	}
	return false;
}

void setup_positions(float robot_pos[ROBOT_COUNT][4])
{

//assign each robot a random position, centered around light source
	int robot_num;
	int x=100;
	int y=100;

	int i = 0; //upper limit for iteration
	while (i < ROBOT_COUNT) {
		float x = (float) rand() * (ARENA_WIDTH-2*radius) / RAND_MAX + radius;
		float y = (float) rand() * (ARENA_HEIGHT-2*radius) / RAND_MAX + radius;
		float theta = rand() * 2 * PI / RAND_MAX;
		if (collision(x, y, robot_pos, i)) {
			continue;
		}
		robot_pos[i][0] = x;
		robot_pos[i][1] = y;
		robot_pos[i][2] = theta;
		robot_pos[i][3] = 0;
		if (i >= NUM_IN_GROUP) {
			robot_pos[i][3] = 1;
		}
		if (i >= NUM_IN_GROUP * 2) {
			robot_pos[i][3] = 2;
		}
		i++;
	}

}
