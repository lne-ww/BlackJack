class dealer_action {   //dealer's action
	public:
		void getcard(int turn);        //add a card to dealer's hand card
		int determine(int dealer_card[],int random,int d);  //decide to pick a card or not,return 1 or 0.  If d = 1,return total point
		void stand();	       //dealer decide to stand,return 1 or 0
		void comments(int a); 	   //say some thing
		int sumpoint();				//sum up dealer's cards
		int dealer_card[9] = {0};	//dealer's hand cards
};