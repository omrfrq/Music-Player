// MusicPlayer.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<iostream>
#include<windows.h>
#include<string>
#include<cstring>
#include<queue>
#include<stack>

using namespace std;

stack<string>s;
queue<string>q;
queue<string>c_q;

struct node
{
	int id = 0;
	string name = "NULL";
	node* next = NULL;
	node* prev = NULL;
};

class music_player
{
public:

	node* head;
	int counter;

	music_player()
	{
		head = NULL;
		counter = 0;
	}
	/******************************************* PLAY SONG FUNCTIONS *******************************************************************************************/
	void p_song(string p)
	{
		stack<string> s;
		s.push(p);
		LPCSTR path;
		path = p.c_str();

		PlaySoundA(path, NULL, SND_SYNC);

	}


	void play_song_1(string p)
	{
		//LPCWSTR path;
		LPCSTR path = p.c_str();
		PlaySoundA(path, NULL, SND_SYNC);

	}

	bool add_node(string nam)
	{

		node* n = new node;
		n->name = nam;

		if (head == NULL)
			head = n;
		else
		{
			node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = n;
		}
		system("cls");
		cout << "\t\t\t " << nam << " is playing.\n";

		counter++;
		char z = 'o';
		while (z == 'y' || z == 'n');
		{

			cout << "press 'y' to play song press 'n' to only add in songlist: "; cin >> z; cout << endl;
			if (z == 'y')
			{
				p_song(n->name);
			}
			else if (z == 'n')
			{
			}
			else
			{
				cout << "invalid input";
			}
		}

		s.push(n->name);

		int x;
		cout << "PRESS 1 TO ADD SONG TO A PLAYLIST.\nPRESS 0 TO EXIT\n";
		cin >> x;
		if (x == 1)
		{
			q.push(n->name);
			c_q.push(n->name);
		}
		else if (x == 0)
			system("pause");

		if (z == 'n')
			return true;
		else
			return false;

	}

	void add_node_1(string nam)
	{
		node* n = new node;
		n->name = nam;

		if (head == NULL)
		{
			head = n;
		}
		else
		{
			node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = n;
		}
		counter++;
	}

	/******************************************* DELETE SONG FUNCTION *******************************************************************************************/
	void del_node(string i)
	{
		if (head == NULL)
		{
			cout << "list is empty" << endl;
		}
		else
		{
			node* temp_node = NULL;
			node* temp = head;
			node* t = head;

			while (temp->next != NULL && temp->name != i)
			{
				t = temp;
				temp = temp->next;
			}

			if (temp->name != i)
			{
				cout << "invalid input\n";
			}
			else if (temp == head)
			{
				node* temp = head->next;
				delete head;
				head = temp;
				counter--;
				cout << "number of songs in playlist: " << counter << endl;
			}
			else if (temp->name == i)
			{
				temp_node = temp;
				temp = temp->next;
				t->next = temp;
				cout << temp_node->name << " deleted\n";
				delete temp_node;
				counter--;
				cout << "number of songs in playlist: " << counter << endl;
			}
		}
	}
	/******************************************* DELETE ALL SONGS FUNCTION *******************************************************************************************/

	void del_songlist()
	{
		node* temp = head;
		if (head == NULL)
		{
			cout << "list is empty" << endl;
		}
		else
		{
			while (temp != NULL)
			{
				temp = head->next;
				delete head;
				head = temp;
				temp = temp->next;
				counter--;
			}
			head = NULL;
			counter--;
		}
	}

	/******************************************* SEARCH SONG FUNCTION *******************************************************************************************/

	string search(string i)
	{
		node* temp = head;
		if (head == NULL)
		{
			cout << "list empty";
		}
		else
		{
			while (temp->next != NULL && temp->name != i)
			{
				temp = temp->next;
			}
		}
		string x = temp->name;
		return x;
	}

	/******************************************* RECENTLY PLAYED SONG FUNCTION ***********************************************************************/

	void recently_played()
	{
		if (s.empty())
			cout << "NO RECENTLY SONG IS PLAYED.\n";
		else
		{
			string ss = s.top();
			int choice;
			cout << "PRESS 1 TO PLAY RECENT SONG.\nPRESS 0 TO VIEW JUST NAME OF RECENT SONG.\n";
			cin >> choice;
			if (choice == 1)
			{
				cout << "recently played song is " << s.top() << endl;
				p_song(ss);
				s.pop();
			}
			else if (choice == 0)
			{
				cout << "recently played song is " << s.top() << endl;
				s.pop();
			}

		}
	}

	/******************************************* PLAYLIST FUNCTION ***********************************************************************/

	void play_list()
	{
		node* n = new node;

		if (head == NULL)
			cout << "Play List is Empty.\n";
		else
		{
			cout << "\n\nPRESS 1 TO SHOW PLAYLIST .\n PRESS 2 TO PLAY PLAYLIST.\n PRESS 0 TO EXIT.\n ";
			int choice;
			cout << "Enter Choice = ";
			cin >> choice;
			if (choice == 1)
			{
				if (q.empty())
					cout << "play list is empty.\n";
				else
				{

					cout << "\t\t\t\tPlayList\n\n\n";
					while (!q.empty())
					{
						string n = q.front();
						cout << "---->" << n << endl;
						q.pop();

					}
				}
			}
			else if (choice == 2)
			{
				if (c_q.empty())
					cout << "PLAY LIST IS EMPTY.\n";
				else {
					while (!c_q.empty())
					{
						cout << c_q.front() << " is p0laying from the playlist.\n ";
						p_song(c_q.front());
						c_q.pop();

					}
				}
			}
			else if (choice == 0)
				system("pause");


		}
	}

	/******************************************* DISPLAY AVAILABLE MUSIC FUNCTION *********************************************************************************/

	void display()
	{
		if (head == NULL)
		{
			cout << "list is empty" << endl;
		}
		else
		{
			int i = 1;
			node* temp = head;
			while (temp != NULL)
			{
				cout << " " << i << "." << temp->name << endl;
				i++; temp = temp->next;
			}
		}
	}

};
//////////////////////////////////////////////////// MAIN //////////////////////////////////////////////////////
int main()
{
	system("color 0B");
	cout << "\n\n\t\t\t\t\t\tWELCOME TO GENIoS MUSIKPLAYER\t\t\t\t\n\n\n";

	music_player mp;
	mp.add_node_1("abc.wav");
	mp.add_node_1("xyz.wav");


	int choice = -1;
	bool brk = false;

	while (brk != true)
	{
		/******************************** MENU DISPLAY **************************************************************************/

		cout << "\t\t\t\tGENIoS MUSIKPLAYER FUNCTIONALITIES.\n\n\n\n";

		cout << " \t\tpress 1 to play a song\n";
		cout << " \t\tpress 2 to display all songs\n";
		cout << " \t\tpress 3 to search the song you wish to play\n";
		cout << " \t\tpress 4 to delete a song from the songlist\n";
		cout << " \t\tpress 5 to select playlist\n";
		cout << " \t\tpress 6 to play the most recently played songs\n";
		cout << " \t\tpress 7 to delete the all songs\n";
		cout << " \t\tpress 0 to exit\n\n";
		cout << " \t\tEnter your choice: "; cin >> choice; cout << endl << endl;

		switch (choice)
		{
		case 1:
		{
			//insert/add_node
			system("CLS");
			string song;
			cout << "\t\t\tEnter song name: "; cin >> song; cout << endl;

			bool chek = mp.add_node(song);
			system("CLS");
			char z;
			if (chek == false)
			{
				do
				{
					cout << "press 'y' to repeat song 'n' to exit: "; cin >> z; cout << endl;
					if (z == 'y')
					{
						mp.play_song_1(song);
					}
					else if (z == 'n')
					{
						break;
					}
					else
					{
						cout << "invalid input";
					}
				} while (z == 'y' || z == 'n');
			}
			else
			{
				system("pause");
			}
		}
		break;

		case 2:
		{
			//display playlist
			system("CLS");
			mp.display();
			cout << endl << endl;
		}
		break;

		case 3:
		{
			//search
			system("CLS");
			mp.display(); cout << endl << endl;
			string i;
			cout << "\t\t\tEnter the song name: "; cin >> i;
			string path = mp.search(i);
			if (path == i)
			{
				mp.add_node(path);
				system("CLS");
			}
			else
			{
				cout << "invalid input";
			}
		}
		break;

		case 4:
		{
			//delete
			system("CLS");
			mp.display();
			string i;
			cout << "\t\t\tEnter the song name: "; cin >> i;
			mp.del_node(i);
			mp.display();
		}
		break;

		case 5:
		{
			//make playlist
			system("CLS");
			mp.play_list();
		}
		break;

		case 6:
		{
			//recently played
			system("CLS");
			mp.recently_played();
		}
		break;

		case 7:
		{
			//delete playlist
			system("CLS");
			mp.del_songlist();
			mp.display();
		}
		break;

		case 0:
		{
			brk = true;
		}
		break;

		default:
		{
			cout << "invalid input";
		}
		}
	}
	system("CLS");
	cout << "\n\n\t\t\t\tTHANK U FOR USING GENIoS MUSIKPLAYER\n\n";
}