#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "rlyres.h"
int main()
{
    int choice,ticket_no,result;
    Passenger *ptr;
    char * pmob_no;
    char* ptrain_no;
    int * pticket_no;
    add_trains();
    while(1)
    {
        choice=enterchoice();
        if(choice==9)
            exit(0);
        switch(choice)
        {
                        case 1:
                                    clrscr();
                                    view_trains();
                                    getch();
                                    clrscr();
                                    break;
                       case 2:
                                    clrscr();
                                    ptr=get_Passenger_details();
                                    if(ptr!=NULL)
                                    {
                                        ticket_no=book_ticket(*ptr);
                                        if(ticket_no==-1)
                                        {
                                            textcolor(LIGHTRED);
                                            printf("Booking failed\n");
                                        }
                                        else
                                        {
                                            textcolor(LIGHTGREEN);
                                            printf("Ticket successfully booked.Your ticket no is %d\n",ticket_no);
                                        }
                                            textcolor(WHITE);
                                            printf("Press any key to continue");
                                            getch();
                                            clrscr();
                                        }
                                    break;
                       case 3:
                                    clrscr();
                                    ticket_no=accept_ticket_no();
                                    if(ticket_no!=0)
                                    {
                                    view_ticket(ticket_no);
                                    textcolor(WHITE);
                                    printf("\nPress any key to go back to the main screen");
                                    getch();
                                    clrscr();
                                    }
                                    break;
                       case 4:
                                    clrscr();
                                    pmob_no=accept_mob_no();
                                    if(pmob_no!=NULL)
                                    {
                                        pticket_no=get_ticket_no(pmob_no);
                                        view_all_tickets(pmob_no,pticket_no);
                                    }
                                    clrscr();
                                    break;
                       case 5:
                                    clrscr();
                                    view_all_bookings();
                                    clrscr();
                                    break;
                      case 6:
                                    clrscr();
                                    ptrain_no=accept_train_no();
                                    if(ptrain_no!=0)
                                    {
                                        view_bookings(ptrain_no);
                                    }
                                    clrscr();
                                    break;
                      case 7:
                                    clrscr();
                                    ticket_no=accept_ticket_no();
                                    if(ticket_no!=0)
                                    {
                                    result=cancel_ticket(ticket_no);
                                    if(result==0)
                                      {
                                        textcolor(LIGHTRED);
                                        printf("Sorry!No tickets booked against the ticket no %d",ticket_no);
                                      }
                                    else if(result==1)
                                      {
                                        textcolor(LIGHTGREEN);
                                        printf("\nTicket no %d succesfully cancelled",ticket_no);
                                      }
                                       else if(result==2)
                                      {
                                        textcolor(LIGHTRED);
                                        printf("\nSorry!Error in cancellation Try again");
                                      }
                                    textcolor(WHITE);
                                    printf("\n\nPress any key to go back to the main screen!");
                                    getch();
                                    }
                                    clrscr();
                                    break;
                      case 8:
                                    clrscr();
                                    ptrain_no=accept_train_no();
                                     if(ptrain_no!=0)
                                    {
                                    result=cancel_train(ptrain_no);
                                    if(result==0)
                                      {
                                        textcolor(LIGHTRED);
                                        printf("Sorry!No tickets booked against the train no %s",ptrain_no);
                                      }
                                    else if(result==1)
                                      {
                                        textcolor(LIGHTGREEN);
                                        printf("\nAll the bookings against train no %s succesfully cancelled",ptrain_no);
                                      }
                                       else if(result==1)
                                      {
                                        textcolor(LIGHTRED);
                                        printf("\nSorry!Error in cancellation Try again");
                                      }
                                    textcolor(WHITE);
                                    printf("\n\nPress any key to go back to the main screen!");
                                    getch();
                                    }
                                    clrscr();
                                    break;
                      default:
                                      textcolor(LIGHTRED);
                                      printf("Wrong Choice! Try Again\n");
                                      textcolor(CYAN);
                                      printf("Press any key to continue");
                                      getch();
                                      clrscr();
        }
    }

    return 0;
}
