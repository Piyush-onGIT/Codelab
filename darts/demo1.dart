class student {
	int roll = 0;
	student(int r) {
		roll = r;
	}
}
void main() {
	student piyush = new student(12);
	print(piyush.roll);
}