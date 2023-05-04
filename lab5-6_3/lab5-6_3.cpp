#include "Header.h"

int main()
{
	//Композиты
	CompositeQuestion* AboutTemperature = new CompositeQuestion();
	CompositeQuestion* AboutCough = new CompositeQuestion();

	//Отдельные вопросы
	LeafQuestion* TemperatureQuestion = new LeafQuestion("Question about temperature");
	LeafQuestion* CoughQuestion = new LeafQuestion("Question about cough");

	//Для Температуры
	AboutTemperature->AddQuestion(TemperatureQuestion);
	AboutTemperature->AddQuestion(CoughQuestion);

	//Для Температуры
	AboutCough->AddQuestion(CoughQuestion);
	AboutCough->AddQuestion(TemperatureQuestion);

	//Вывод результата
	cout << "About Temparature" << endl;
	AboutTemperature->PrintQuestion();
	cout << "About Cough" << endl;
	AboutCough->PrintQuestion();

	cout << "In questions about cough, there are no questions about temperature!" << endl;
	//Удаляем вопрос про температуру
	AboutCough->RemoveQuestion(TemperatureQuestion);

	//Снова выводим
	cout << "About Cough" << endl;
	AboutCough->PrintQuestion();

	delete AboutTemperature, AboutCough;
	delete TemperatureQuestion, CoughQuestion;
}

