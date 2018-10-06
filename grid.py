from turtle import*
import sys

# Ask the user for the size of the checkered flag (n).
def getSize():
  size = eval(input('Please enter the size of the checkered flag: '))
  return size

# Draw an n x n grid to the screen.
def drawGrid(turtle, n):
  for i in range(0, n+1):
    turtle.up()
    turtle.goto(0, i)
    turtle.down()
    turtle.forward(n)
  turtle.left(90)
  for i in range(0, n+1):
    turtle.up()
    turtle.goto(i, 0)
    turtle.down()
    turtle.forward(n)

# Fill the square in the given row and column.
def fillSquare(turtle, row, col):
  turtle.fillcolor('black')
  turtle.up()
  turtle.goto(col, row)
  turtle.begin_fill()
  for i in range(4):
    turtle.forward(1)
    turtle.right(90)
  turtle.end_fill()

def fillSquare2(turtle, row, col):
      turtle.fillcolor('green')
      turtle.up()
      turtle.goto(col, row)
      turtle.begin_fill()
      for i in range(4):
        turtle.forward(1)
        turtle.right(90)
      turtle.end_fill()

def fillSquare3(turtle, row, col):
      turtle.fillcolor('blue')
      turtle.up()
      turtle.goto(col, row)
      turtle.begin_fill()
      for i in range(4):
        turtle.forward(1)
        turtle.right(90)
      turtle.end_fill()      

def main():
  # Get the user's input.
  #n = getSize()
  n=10
  # Set up the drawing coordinates.
  screen = Screen()
  screen.setworldcoordinates(-1, -1, 10, 10)
  #screen.setworldcoordinates(10, 10, -1, -1)


  # Make a turtle object for use in drawing. Maximize its speed.
  turtle = Turtle()        
  #turtle.speed('fastest')
  turtle.speed(100)
  turtle.hideturtle()      

  # Draw the checkered flag.
  drawGrid(turtle, n)
  co1=(sys.argv[1][0],sys.argv[1][1]);
  co2=(sys.argv[1][2],sys.argv[1][3]);
  co3=(sys.argv[1][4],sys.argv[1][5]);
  co4=(sys.argv[1][6],sys.argv[1][7]);
  co5=(sys.argv[1][8],sys.argv[1][9]);
  co6=(sys.argv[1][10],sys.argv[1][11]);
  co7=(sys.argv[1][12],sys.argv[1][13]);
  co8=(sys.argv[1][14],sys.argv[1][15]);
  co9=(sys.argv[1][16],sys.argv[1][17]);
  co10=(sys.argv[1][18],sys.argv[1][19]);
  co11=(sys.argv[1][20],sys.argv[1][21]);
  co12=(sys.argv[1][22],sys.argv[1][23]);
  co13=(sys.argv[1][24],sys.argv[1][25]);
  co14=(sys.argv[1][26],sys.argv[1][27]);
  co15=(sys.argv[1][28],sys.argv[1][29]);
  co16=(sys.argv[1][30],sys.argv[1][31]);
  co17=(sys.argv[1][32],sys.argv[1][33]);
  co18=(sys.argv[1][34],sys.argv[1][35]);
  co19=(sys.argv[1][36],sys.argv[1][37]);
  co20=(sys.argv[1][38],sys.argv[1][39]);
  co21=(sys.argv[1][40],sys.argv[1][41]);
  co22=(sys.argv[1][42],sys.argv[1][43]);
  co23=(sys.argv[1][44],sys.argv[1][45]);
  co24=(sys.argv[1][46],sys.argv[1][47]);
  co25=(sys.argv[1][48],sys.argv[1][49]);
  #co26=(sys.argv[1][50],sys.argv[1][51]);
  #co27=(sys.argv[1][52],sys.argv[1][53]);
  #co28=(sys.argv[1][54],sys.argv[1][55]);
  #co29=(sys.argv[1][56],sys.argv[1][57]);
  #co30=(sys.argv[1][58],sys.argv[1][59]);
  fillSquare3(turtle,0,0)
  fillSquare3(turtle,9,9)
  valuesToCheck = [co1,co2,co3,co4,co5,co6,co7,co8,co9,co10,co11,co12,co13,co14,co15,co16,co17,co18,co19,co20,co21,co22,co23,co24,co25]
  for i in valuesToCheck:
    fillSquare(turtle,int(i[1]),int(i[0]))
    #row = 0
    #offset = ~(n % 2) & (row % 2)
    #col = 0
    #fillSquare(turtle, row, col)

  #pa1=(0,0)
  #pa2=(0,1)
  #pa3=(1,2)
  #pa4=(2,3)
  #pa5=(3,4)
  #pa6=(4,5)
  #pa7=(5,6)
  #pa8=(6,7)
  #pa9=(7,8)
  #pa10=(8,9)
  #pa11=(9,9)

  for i in range(0,len(sys.argv[2]),2):
    fillSquare2(turtle,int(sys.argv[2][i+1]),int(sys.argv[2][i]))
    if(sys.argv[2][i+1]==9 and sys.argv[2][i]==9):
      break  
  print('Hit Enter to quit.')
  input()




"""
  pa1=(sys.argv[2][0],sys.argv[2][1]);
  pa2=(sys.argv[2][2],sys.argv[2][3]);
  pa3=(sys.argv[2][4],sys.argv[2][5]);
  pa4=(sys.argv[2][6],sys.argv[2][7]);
  pa5=(sys.argv[2][8],sys.argv[2][9]);
  pa6=(sys.argv[2][10],sys.argv[2][11]);
  pa7=(sys.argv[2][12],sys.argv[2][13]);
  pa8=(sys.argv[2][14],sys.argv[2][15]);
  pa9=(sys.argv[2][16],sys.argv[2][17]);
  pa10=(sys.argv[2][18],sys.argv[2][19]);
  pa11=(sys.argv[2][20],sys.argv[2][21]);
  pa12=(sys.argv[2][22],sys.argv[2][23]);
  pa13=(sys.argv[2][24],sys.argv[2][25]);
  pa14=(sys.argv[2][26],sys.argv[2][27]);
 
  pa15=(sys.argv[2][28],sys.argv[2][29]);
  pa16=(sys.argv[2][30],sys.argv[2][31]);
  pa17=(sys.argv[2][32],sys.argv[2][33]);
  pa18=(sys.argv[2][34],sys.argv[2][35]);
  pa19=(sys.argv[2][36],sys.argv[2][37]);
  pa20=(sys.argv[2][38],sys.argv[2][39]);
  pa21=(sys.argv[2][40],sys.argv[2][41]);
  pa22=(sys.argv[2][42],sys.argv[2][43]);
  pa23=(sys.argv[2][44],sys.argv[2][45]);
  pa24=(sys.argv[2][46],sys.argv[2][47]);
  pa25=(sys.argv[2][48],sys.argv[2][49]);
  



  valuesToCheck2 = [pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12,pa13,pa14]
  for i in valuesToCheck2:
    fillSquare2(turtle,int(i[1]),int(i[0]))



"""

main()