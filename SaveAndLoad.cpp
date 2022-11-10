#include "SaveAndLoad.h"

void Save(PlayerList* root)
{
	Json::Value rootObject;//define the root node, that is, the outermost { }
	Json::Value playerArray;
	Json::StyledWriter sw;

	string name, result;
	int coin;
	Time time;
	
	//It's hard for me to describe. Just ask me when you don't understand.
	PlayerList* p = root;
	while (p->next != NULL)
	{
		Json::Value playerObject;
		Json::Value value;//it can be anything

		p = p->next;
		value = p->player->getName();
		playerObject["name"] = value;

		Record* r = p->player->getRoot();
		Json::Value recordArray;
		while (r->next != NULL)
		{
			Json::Value recordObject;

			r = r->next;

			time = r->time;
			value = time.getYear();
			recordObject["year"] = value;
			value = time.getMon();
			recordObject["month"] = value;
			value = time.getDay();
			recordObject["day"] = value;
			value = time.getHour();
			recordObject["hour"] = value;
			value = time.getMin();
			recordObject["minute"] = value;
			value = time.getSec();
			recordObject["second"] = value;
			value = r->coin;
			recordObject["coin"] = value;
			value = r->result;
			recordObject["result"] = value;

			recordArray.append(recordObject);
		}
		
		playerObject["record"] = recordArray;

		playerArray.append(playerObject);
	}

	rootObject["player"] = playerArray;
	ofstream File;
	string FilePosition = "saved.json";
	File.open(FilePosition, ios::out | ios::trunc);
	if (!File.is_open())
		cout << "error£ºcan not find or create the file." << endl;
	File << sw.write(rootObject);
	File.close();
	cout << "Save successfully£¡" << endl;
}

void Load(PlayerList* rootList)
{
	string name, result;
	int coin;
	int year, mon, day, hour, min, sec;
	Time time;

	Json::Reader reader;
	Json::Value value;
	string FilePosition;
	ifstream File;
	FilePosition = "saved.json";
	File.open(FilePosition, ios::in | ios::binary);//open the file in binary
	if (!File.is_open()) cout << "Fail to open the file." << endl;
	if (reader.parse(File, value))
	{
		PlayerList* pl = rootList;
		int playerSize = value["player"].size();
		for (int i = 0; i < playerSize; i++)
		{
			PlayerList* q = new PlayerList;

			name = value["player"][i]["name"].asString();
			Player* p = new Player(name);
			int recordSize = value["player"][i]["record"].size();
			for (int j = 0; j < recordSize; j++)
			{
				coin = value["player"][i]["record"][j]["coin"].asInt();
				result= value["player"][i]["record"][j]["result"].asString();
				year= value["player"][i]["record"][j]["year"].asInt();
				mon = value["player"][i]["record"][j]["month"].asInt();
				day = value["player"][i]["record"][j]["day"].asInt();
				hour = value["player"][i]["record"][j]["hour"].asInt();
				min = value["player"][i]["record"][j]["minute"].asInt();
				sec = value["player"][i]["record"][j]["second"].asInt();
				time.setTime(year, mon, day, hour, min, sec);
				p->setRecord(time, coin, result);
				if (j == recordSize - 1) p->iniCoin(coin);
			}

			q->player = p;
			q->next = NULL;
			pl->next = q;
			pl = pl->next;
		}
	}
}