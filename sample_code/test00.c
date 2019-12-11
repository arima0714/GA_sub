#include <GL/glut.h>

double vertices[][3] = {
	{0.0, 0.5, 0.0},
	{0.0, 0.0, 0.0},
	{0.5, 0.0, 0.0},
	{0.5, 0.5, 0.0}
};

double tx = 0.0;
double ty = 0.0;
double tz = 0.0;
double rx = 0.0;
double ry = 0.0;
double rz = 0.0;

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();	// 視野変換・モデリング変換の変換行列を単位行列で初期化
	glTranslated(tx, ty, tz);	// 平行移動
	glRotated(rx, 1.0, 0.0, 0.0);	// x軸回転
	glRotated(ry, 0.0, 1.0, 0.0);	// y軸回転
	glRotated(rz, 0.0, 0.0, 1.0);	// z軸回転

	// モデリング座標系
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	for(int i = 0; i < 4; i++){
		glVertex3dv(vertices[i]);
	}
	glEnd();

	glFlush();
}

void resize(int w, int h){
	glViewport(0,0,w,h);	// ウィンドウ全体に表示
	glMatrixMode(GL_PROJECTION);	// 投影変換モードへ
	glLoadIdentity();	// 投影変換の変換行列を単位行列で初期化
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);	// 各軸 -1.0 ~ 1.0 で囲まれる立方体の範囲を並行投影
	glMatrixMode(GL_MODELVIEW);	// 視野変換・モデリング変換モードへ
	glLoadIdentity();	// 視野変換・モデリング変換の変換行列を単位行列で初期化
}

void keyboard(unsigned char key, int x, int y){
	switch (key){
		case '4':
			tx -= 0.01;
			break;
		case '6':
			tx += 0.01;
			break;
		case '2':
			ty -= 0.01;
			break;
		case '8':
			ty += 0.01;
			break;
		case '9':
			tz -= 0.01;
			break;
		case '1':
			tz += 0.01;
			break;
		case 'x':
			rx += 2.0;
			break;
		case 'y':
			ry += 2.0;
			break;
		case 'z':
			rz += 2.0;
			break;
		default:
			break;
	}
	glutPostRedisplay();
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);

	glutInitWindowPosition(100, 100);	// ウィンドウを画面左上に表示
	glutInitWindowSize(320, 240);	// ウィンドウのサイズ

	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);	// 関数resizeをコールバックに設定
	glutKeyboardFunc(keyboard);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutMainLoop();
	return 0;
}

