	#include "connect.h"

    
	CONNECT4::CONNECT4()
	{
		size=7;
		won=false; // variable for determining either player won or not.
		turn=1;
		for(int row=0; row<size; row++)
		{
		    for(int col=0; col<size; col++)
			{
			   arr[row][col]=0;
			}
		}
	}
	
	void CONNECT4::ShowBoard()
   {
	int count=0;
    cout<<"\n\t+";
	for(count=0; count<size; count++) // loop for displaying upper line
	{
	cout<<"------+";
	}
	cout<<"\n\t|";

	for(count=1;count<=size;count++) // loop for displaying counting
	{
	cout<<"   "<<count<<"  |";
	}

	cout<<"\n\t+";
	for(count=0; count<size; count++) // loop for displaying lower line
	{
	cout<<"------+";
	}
	 cout<<"\n\n\t\t   THROW YOUR ELEMENT FROM TOP\n"<<endl;

	cout<<"        +";
	for(count=0;count<size;count++) // loop for displaying upper line of board
	{
			cout<<"------";
			if(count==size-1)
			{
			cout<<"+\n";
			}
			else
			{
			cout<<"|";
			}
	}
		
	for(int row=0;row<size;row++)
	{
			cout<<"        |";
		    for(int col=0; col<size ; col++)
		    {	
		     cout<<"  "<<arr[row][col]<<"   |"; // for listing indexes of array on screen in a row;
		    }
		    cout<<"\n        ";

		    for(count=0;count<size;count++)
		    {
			  if(count==0)
			  {
			  cout<<"+";
			  }
			  else
			  {
			   cout<<"|"; // for displaying line after each row of array indexes
			  }
			  cout<<"------";
		    }
		   cout<<"+"<<endl;
	}
	cout<<endl;
}

	bool CONNECT4::OutofBound(int row,int column) // for checking indexes of array so that program can not use indexes that are not in it.
{
	bool check=false;
	for(int i=0;i<size;i++)
	{
	   for(int j=0;j<size;j++)
	   {
	     if(i==row)
	     {
		   if(j==column)
		   {
	       check=true;
	       break; // for breaking inner loop
		   }
	     }
	   }
   if(check==true)
   {
	 break; // for breaking outerloop
   }
	}
	return check;
}

	bool CONNECT4::IsWon(int row, int column)
{
	bool check=false;
	int value=arr[row][column];
	int count=1;
	int counter=column+4;
	for(int col=column+1; col<counter; col++) // loop for checking right side
	{
		check=OutofBound(row,col);
		if(check==true)
		{
	         if(arr[row][col]==value)
		     {
		         count++;
		     }
		     if(count==4)
		     {
		         won=true;
				 break;
		     }
		     if(arr[row][col]!=value)
		     {
		          break;
		     }
		}
		else // check=false;
		{
		break;
		}
	}

	if(won==false)
	{
	      counter=column-4;
	      for(int col=column-1; col>counter; col--) // loop for checking left side
	      {
		      check=OutofBound(row,col);
		      if(check==true)
		      {
	               if(arr[row][col]==value)
		           {
		                count++;
		           }
		           if(count==4)
		           {
		                won=true;
		                break;
		           }
		           if(arr[row][col]!=value)
		           {
		                break;
		           }
		      }
		      else
		      {
		          break;
		      }
	     }
	}

	if(won==false)
	{
	       count=1;
	       counter=row+4;
	       for(int rowcopy=row+1; rowcopy<counter; rowcopy++) // loop for checking at bottom 
	       {
	          	check=OutofBound(rowcopy,column);
		        if(check==true)
		        {
	                  if(arr[rowcopy][column]==value)
		              {
		                   count++; 
		              }
		              if(count==4)
		              {
		                   won=true;
				           break;
		              }
		              if(arr[rowcopy][column]!=value)
		              {
		                   break;
		              }
		         }
		        else
		        {
		             break;
		        }
	       }
	}

	if(won==false)
	{
		count=1;
       	counter=row-4; // counter=column-4 can also be written here.
	    for(int rowcopy=row-1,col=column-1; rowcopy>counter; rowcopy--,col--) // loop for checking at top left 
	    {
		      check=OutofBound(rowcopy,col);
		      if(check==true)
		      {

	                if(arr[rowcopy][col]==value)
		            {
		                count++;
		            }
					if(count==4)
					{
					won=true;
					break;
					}
		            if(arr[rowcopy][col]!=value)
		            {
		                  break;
		            }
		      }
		      else
		      {
		          break;
		      }
	    }
		
}

	if(won==false)
	{
	      counter=row+4; // counter=column+4 can also be written here.
	      for(int rowcopy=row+1,col=column+1; rowcopy<counter; rowcopy++,col++) // loop for checking at bottom right 
	       {
	            check=OutofBound(rowcopy,col);
		        if(check==true)
		        {
	                   if(arr[rowcopy][col]==value)
		               {
		                  count++;
		               }
		               if(count==4)
		               {
		                   won=true;
				           break;
		               }
		               if(arr[rowcopy][col]!=value)
		               {
		                   break;
		               }
		        }
		        else
		        {
		           break;
		        }
	       }
	}
	if(won==false)
	{
		    count=1;
	        counter=row-4; 
	        for(int rowcopy=row-1,col=column+1; rowcopy>counter; rowcopy--,col++) // loop for checking at top right 
	        {
	          	check=OutofBound(rowcopy,col);
		         if(check==true)
		         {
	                    if(arr[rowcopy][col]==value)
		                {
		                     count++;
		                }
		                if(count==4)
		                {
		                     won=true;
				             break;
		                }
		               if(arr[rowcopy][col]!=value)
		               {
		                    break;
		               }
		         }
		        else
		         {
		             break;
		         }
	        }
	}

	if(won==false)
	{
	       counter=row+4; // counter=column-4 can also be written here.
	       for(int rowcopy=row+1,col=column-1; rowcopy<counter; rowcopy++,col--) // loop for checking at bottom left 
	       {
		          check=OutofBound(rowcopy,col);
		          if(check==true)
		          {
	                   if(arr[rowcopy][col]==value)
		               {
		                  count++;
		               }
		               if(count==4)
		               {
		                  won=true;
				          break;
		               }
		               if(arr[rowcopy][col]!=value)
		               {
		                  break;
		               }
		          }
		          else
		          {
		              break;
		          }
	       }
	}
	 if(won==true)
		 {
			system("cls");
			ShowBoard();
			cout<<"Congratulations! Player "<<turn<<" you won!"<<endl;
		 }
	return won;
}

	bool CONNECT4::SpaceCheck(int column) // for checking where to place the user value in a user entered column
{
	 bool check=false;
     column=column-1;
	 for(int row=0;row<size;row++)
	 {
	     if(arr[row][column]!=0)
		 {      
			   check = OutofBound(row-1,column);
			   if(check==true)
			   {
			       if(turn==1)
				   {
		           arr[row-1][column]=turn; // turn=1;
				   }
				   else if(turn==2)
				   {
		            arr[row-1][column]=turn; // turn=2;
				   }
			   }
			    if(check==true)
		      {
		         won=IsWon(row-1,column);
		      }
				
			   break;
		 }
		   else if(row==size-1 && arr[row][column]==0)
		 {
		      check=true;
			  if(turn==1)
			  {
		           arr[row][column]=turn; // turn=1;
			  }
			  else if(turn==2)
			  {
		            arr[row][column]=turn; // turn=2;
			  }
			   if(check=true)
		       {
		         won=IsWon(row,column);
		       }
			  break;
		 }
	 }
	 return check;
}

	bool CONNECT4::IsBoardFull()
{
	bool check=false;
	for(int i=0;i<size;i++)
	{
	   for(int j=0;j<size;j++)
	   {
	       if(arr[i][j]==0)
		   {
			   check=true;
			   break; // for breaking innerloop
		   }
	   }
	   if(check==true)
       {
	       break; // for breaking outerloop
       }
	}

	return check;
}

	void CONNECT4::SwitchTurn()
{
           if(turn==1)
			{
			turn=2;
			}
			else if(turn==2)
		    {
			turn=1;
			}
}

	void CONNECT4::Start()
{
	int column=0;
	bool check=true;
	cout<<" 1st Player! Your turn!\n(Enter number of the column) :";
	 while(true)
    {
		cin>>column;
		check=SpaceCheck(column); // function for checking valid move and placing the value
		 if(won==true)
		 {
			 break;
		 }
		if(check==false)
		{
		cout<<"Invalid move. Enter again:";
		}
		else if(check==true)
		{
			system("cls");
			ShowBoard();
		    if(IsBoardFull()==false) // function checking whether the board is full or not
			{
			  cout<<"Draw Game. Board is Full"<<endl;
			  break;
			}
			
			if(turn==1)
			{
			SwitchTurn(); // for switching the turn
			cout<<" 2nd Player! Your turn!\n(Enter number of the column) :";
			}
			else if(turn==2)
		    {
			SwitchTurn();
			cout<<" 1st Player! Your turn!\n(Enter number of the column) :";
			}
			check=false;
			}
	 }
}