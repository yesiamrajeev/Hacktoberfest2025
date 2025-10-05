def Rules(input1,input2):
    global name1,name2,score1,score2
    if input1 == "R" and input2 == "S":
        print(f"{name2} is defeated by {name1}")
        score1 += 1
        print(f"Score of {name1} : {score1} , Score of {name2} : {score2}")
    elif input1 == "R" and input2 == "P":
        print(f"{name1} is defeated by {name2}")
        score2 += 1
        print(f"Score of {name1} : {score1} , Score of {name2} : {score2}")
    elif input1 == "S" and input2 == "R":
        print(f"{name1} is defeated by {name2}")
        score2 += 1
        print(f"Score of {name1} : {score1} , Score of {name2} : {score2}")
    elif input1 == "P" and input2 == "R":
        print(f"{name2} is defeated by {name1}")
        score1 += 1
        print(f"Score of {name1} : {score1} , Score of {name2} : {score2}")
    elif input1 == "S" and input2 == "P":
        print(f"{name2} is defeated by {name1}")
        score1 += 1
        print(f"Score of {name1} : {score1} , Score of {name2} : {score2}")
    elif input1 == "P" and input2 == "S":
        print(f"{name1} is defeated by {name2}")
        score2 += 1
        print(f"Score of {name1} : {score1} , Score of {name2} : {score2}")
    elif input1 == "R" and input2 == "R":
        print(f"{name2} , {name1},Match ties")
        print(f"Score of {name1} : {score1} , Score of {name2} : {score2}")
    elif input1 == "S" and input2 == "S":
        print(f"{name2} , {name1},Match ties")
        print(f"Score of {name1} : {score1} , Score of {name2} : {score2}")
    elif input1 == "P" and input2 == "P":
        print(f"{name2} ,{name1},Match ties")
        print(f"Score of {name1} : {score1} , Score of {name2} : {score2}")
    else:
        print("Wrong Input")
        print(f"Score of {name1} : {score1} , Score of {name2} : {score2}")
        

def RockPaperScissor():
    global score,name1,name2
    print("Welcome to Rock , Paper , Scissor Game")
    print("User 1",end = " ")
    name1 = input("Enter your Name User1: ")
    print("User 2",end = " ")
    name2 = input("Enter your Name User2: ")
    score = int(input("Enter Target Score: "))
    
def Game():
    global score,score1,score2
    RockPaperScissor()
    score1 = 0
    score2 = 0
    print("##########################################")
    while (score1 != score) and (score2 != score):
        input1 = input("\nEnter your Move user1(R/P/S): ")
        q = input1.upper()
        input2 = input("Enter your Move user2(R/P/S): ")
        r = input2.upper()
        Rules(q,r)
    if score == score1:
        print(f"{name1} wins the Game")
    elif score == score2:
        print(f"{name2} wins the Game")
    else:
        print("Match Ties")
    print("##########################################")
    restart = input("Do you want to Restart the Game(Y/N): ").upper()
    if restart == "Y":
        return Game()
    elif restart == "N":
        return "Thanks for Playing the Game"

            
Game()
    
        