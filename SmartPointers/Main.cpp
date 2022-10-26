#include"SmartPointerImpl.cpp"
#include"TransactionImpl.cpp"
#include"Document.h"
#include"IObservable.h"
#include"IObserver.h"
#include"Worker.h"

int menu()
{
	int k;
	cout << endl << "1 Добавить новую информацию" << endl;
	cout << "2 Отменить последние изменения" << endl;
	cout << "3 Очистить буфер" << endl;
	cout << "4 Сменить аккаунт" << endl;
	cout << "5 Счетчик ссылок" << endl;
	cout << "6 Выйти" << endl;
	cin >> k;
	return k;
}



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Worker* arr = new Worker[100];

	bool isFirstAccCheckedOut=true;
	SmartPointer<Transaction<Document>>mainDocument = new Transaction<Document>;
	SmartPointer<Worker> worker = new Worker;
	SmartPointer<Worker> worker_1 = new Worker("", mainDocument, 1);
	SmartPointer<Worker> worker_2 = new Worker("", mainDocument, 2);

	worker = worker_1;

	worker->printData();

	while (true) {
		
		switch (menu()) {
		case 1: {
			worker->writeDataInDocument();
			system("cls");
			worker->printData();
			break;
		}
		case 2: {
			worker->back();
			system("cls");
			worker->printData();
			break;
		}
		case 3: {
			worker->clearBuffer();
			break;
		}
		case 4: {
			system("cls");
			if (isFirstAccCheckedOut) {
				worker = worker_2;
				isFirstAccCheckedOut = false;
			}
			else {
				worker = worker_1;
				isFirstAccCheckedOut = true;
			}
			worker->printData();
			break;
		}
		case 5: {
			system("cls");
			worker->printData();
			worker.showCounter();
			break;
		};
		case 6: return 0;
		default:{
			cout << "Неправильный ввод" << endl;
			}
		}

	}
	
}

