#include"Worker.h"

void Worker::writeDataInDocument() {
	cout << "Enter new date in document" << endl;
	getchar();
	getline(cin, data);
	doc->beginTransactions(data);
}