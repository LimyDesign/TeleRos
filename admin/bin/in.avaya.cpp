// CDR Parser
// Programming by @ArsenBespalov, 2012
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <fstream>
#include <string>

#include <my_global.h>
#include <mysql.h>
#include <errmsg.h>
#include <mysqld_error.h>

#define DB_HOST "localhost"
#define DB_USER "utel"
#define DB_PASS "ptel"
#define DB_BASE "tel"

#define DD "-";
#define DT ":";
#define SP "', '";

using namespace std;
using namespace boost;

int main()
{	
	// Дескриптор соединения
	MYSQL conn;
	
	// Получаем дескриптор соединения
	if (!mysql_init(&conn)) 
	{
		// Если дескриптор не получен - выводим сообщение об ошибке
		fprintf(stderr, "JRate ошибка: невозможно создать MySQL-дескриптор\n");
		exit(1);
	}
	
	// Подключаемся к северу MySQL
	if (!mysql_real_connect(&conn, 
				DB_HOST, 
				DB_USER, 
				DB_PASS, 
				DB_BASE, 
				0, 
				NULL, 
				0))
	{
		// Если соединение не установлено выводим сообщение
		fprintf(stderr, "JRate ошибка: невозможно подключиться к MySQL.\n");
		exit(1);
	}

	// Устанавливаем кодировку соединения, чтобы предотвратить
	// искажения русских и не только символов
	if (mysql_query(&conn, "SET NAMES 'utf8'") != 0)
	{
		// Если кодировку установить невозможно -
		// выводим сообщение об ошибке
		fprintf(stderr, "JRate ошибка: невозможно установить кодировку\n");
		exit(1);
	}
	
	ofstream logfile;
	string s;
	while (getline(cin, s))
	{
		logfile.open("/tmp/cdr2.txt", ios::out | ios::app);
		// cout << "===> len: " << s.length() << " <===" << endl;
		logfile << "===> len: " << s.length() << " <===" << endl;
		logfile << s << endl;
		if (s.length() <= 82 || s.length() >= 79) {

			// Расчленяем исходные данные на составляющие
			string acm_date = s.substr(0,6);
			string acm_time = s.substr(7,4);
			string acm_code_used = s.substr(12,4);
			string acm_out_crt_id = s.substr(17,3);
			string acm_in_trk_code = s.substr(21,4);
			string acm_in_crt_id = s.substr(26,3);
			string acm_clg_num = s.substr(31,10);
			string acm_cond_code = s.substr(44,1);
			string acm_frl = s.substr(47,1);
			string acm_sec_dur = s.substr(50,5);
			string acm_dialed_num = s.substr(56,18);
			string acm_node_num = s.substr(75,2);

			// Режим всякий бутор
			trim(acm_date); trim(acm_time); trim(acm_code_used);
			trim(acm_out_crt_id); trim(acm_in_trk_code); trim(acm_in_crt_id);
			trim(acm_clg_num); trim(acm_cond_code); trim(acm_frl);
			trim(acm_sec_dur); trim(acm_dialed_num); trim(acm_node_num);
			
			// Выделяем части даты
			string acm_day = acm_date.substr(0,2);
			string acm_month = acm_date.substr(2,2);
			string acm_year = acm_date.substr(4,2);

			// Захуяриваем время
			string acm_hours = acm_time.substr(0,2);
			string acm_minuts = acm_time.substr(2,2);

			// cout << "Date: " << acm_date << endl;
			// cout << "Time: " << acm_time << endl;
			// cout << "Code Used: " << acm_code_used << endl;
			// cout << "Out Crt Id: " << acm_out_crt_id << endl;
			// cout << "In Trk Code: " << acm_in_trk_code << endl;
			// cout << "In Crt Id: " << acm_in_crt_id << endl;
			// cout << "Clg Num: " << acm_clg_num << endl;
			// cout << "Cond Code: " << acm_cond_code << endl;
			// cout << "FRL: " << acm_frl << endl;
			// cout << "Sec Dur: " << acm_sec_dur << endl;
			// cout << "Dialed Num: " << acm_dialed_num << endl;
			// cout << "Node Num: " << acm_node_num << endl;

			// Выводим в лог файл!
			logfile << "Date: 20" << acm_year << "-" << acm_month << "-" << acm_day << endl;
			logfile << "Time: " << acm_hours << ":" << acm_minuts << endl;
			logfile << "Code Used: " << acm_code_used << endl;
			logfile << "Out Crt Id: " << acm_out_crt_id << endl;
			logfile << "In Trk Code: " << acm_in_trk_code << endl;
			logfile << "In Crt Id: " << acm_in_crt_id << endl;
			logfile << "Clg Num: " << acm_clg_num << endl;
			logfile << "Cond Code: " << acm_cond_code << endl;
			logfile << "FRL: " << acm_frl << endl;
			logfile << "Sec Dur: " << acm_sec_dur << endl;
			logfile << "Dialed Num: " << acm_dialed_num << endl;
			logfile << "Node Num: " << acm_node_num << endl;

			// Создаем МЕГА запрос...
			// string query = "INSERT INTO acccall2 (`date`, `time`, `code-used`, `out-crt-id`, `in-trk-code`, `in-crt-id`, `clg-num-in-tac`, `cond-code`, `frl`, `sec-dur`, `dialed-num`, `node-num`) VALUES ('20";
			string query = "INSERT INTO acccall2 (`date`, `time`) VALUES ('20";
			query += acm_year + "-" + acm_month + "-" + acm_day + " " + acm_hours + ":" + acm_minuts;
			query += "', '" + acm_time;
			// query += "', '"+acm_code_used;
			// query += "', '"+acm_out_crt_id;
			// query += "', '"+acm_in_trk_code;
			// query += "', '"+acm_in_crt_id;
			// query += "', '"+acm_clg_num;
			// query += "', '"+acm_frl;
			// query += "', '"+acm_sec_dur;
			// query += "', '"+acm_dialed_num;
			// query += "', '"+acm_node_num+"');";
			query += "');";

			if (mysql_query(&conn, query.c_str()) != 0) 
			{
				fprintf(stderr, "Ошибка: не могу записать в MySQL\n");
				logfile << "Ошибка: не могу записать в MySQL" << endl;
				exit(1);
			}
		}
		logfile.close();
	}

	mysql_close(&conn);
	return 0;
}
