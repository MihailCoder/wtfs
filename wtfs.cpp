#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

int main() {
    system("chcp 65001>nul");
	
	srand(time(0));
	
	int max_moves = 10;
	int wood = 0;
	int metal = 0;
	int sh_level = 1;
	int sh_lv_max = 3;
	int movesLeft = max_moves;
	int choice;
	int hp = 100;
	int hp_m = 100;
	
	cout<<"=== Добро пожаловать в мир 'Waiting for the Storm' ==="<< endl;
	cout<<"Сможете ли вы пережить шторм или нет - все зависит от вас!"<< endl;
	cout<<"-------------------------------------------------------"<<endl;
	cout<<"Игра началась!"<< endl;

	do {
		
		if (hp <= 0) {
			cout<<"Ты погиб от ран, к сожалению"<<endl;
		break;
		}
		
		// отображение состояния
		cout << "Ходов осталось: " << movesLeft << endl;
		cout << "Дерево: " << wood << " | Металл: " << metal << endl;
		cout << "Уровень убежища: " << sh_level << "/" << sh_lv_max << endl;
		cout << "Здоровье: " << hp << endl;
    
		// меню
		cout << "\n1 - Отправиться в густой лес - там можно добыть дерево" << endl;
		cout << "2 - Отправиться в металлическую долину - там можно собрать обломки металла" << endl;
		cout << "3 - Укрепить убежище" << endl;
		cout << "4 - Закончить игру (сдаться)" << endl;
		cout << "5 - Отдохнуть (восстанавливает ХП)" << endl;
		cout << "Выберите действие: ";
    
		cin >> choice;
		
		switch (choice) {
			case 1:
			// собрать дерево
				wood += rand() % 3 + 3;
				movesLeft--;
				if (rand() % 11 <= 4){
					hp -= rand() % 4 + 3;
					cout<<" Вы получили урон!"<< endl;
				}
				break;
			case 2:
            // собрать металл
				metal += rand() % 2 + 2;
				movesLeft--;
				if (rand() % 11 <= 4){
					hp -= rand() % 4 + 3;
					cout<<" Вы получили урон!"<< endl;
				}
				break;
			case 3: {
			//Убежище
			if (wood >= 2 && metal >= 1 && sh_level == 1) {
				wood -= 2;
				metal--;
				sh_level++;
				movesLeft--;
				cout<<"Ваша база была улучшена до второго уровня! для третьего неободимо: 5 металла и 3 дерева. "<<endl;
			} 
			else if (wood >= 3 && metal >= 5 && sh_level == 2) {
				wood -= 3;
				metal -= 5;
				sh_level++;
				movesLeft--;
				cout<<"Ваша база была полностью улучшена!"<<endl;
			}	
			else {
				cout<<" Не хватает ресурсов либо база уже полностью улучшена."<< endl;
			}
				break;
			}	
			case 4: {
				cout << "Ты сдался... Шторм поглотил тебя." << endl;
				break;
			}
			//Удалить или закоментировать - для теста
			case 5: {
				if (hp >= hp_m) {
					cout<<"Ты уже полностью здоров. отдых не нужен."<<endl;
				}
				else {
					int heal = rand() % 6 + 15; 
					hp += heal;
					if (hp > hp_m) hp = hp_m;
					movesLeft--;
					cout << "Ты отдохнул и восстановил " << heal << " HP." << endl;
				}
				break;
			}
			default:
				cout << "Неверный выбор. Попробуй снова." << endl;
			}
    
} while (movesLeft > 0 && choice != 4);
	
	// Шторм
	if (movesLeft <= 0) {
		cout<<"Шторм начался!"<<endl;
		if (sh_level == sh_lv_max) {
			cout<<"Вы смогли пережить шторм."<<endl;
		}
		else {
			cout<<"К сожелению, ваша база не смогла спасти вас от катострофы"<<endl;
		}
	}
		
	
    system("pause>nul");
    return 0;
}
 //код создан без ГМО (ИИ :D)