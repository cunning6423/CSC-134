from turtle import*

t= Turtle()
t.pensize(3)
t.speed(1500)
t.pencolor("CornflowerBlue")
# square - 90 degrees * 4 is 360

#t.begin_fill()  #fill this shape
t.fillcolor("sienna4")
t.begin_fill()
t.circle(100)
t.end_fill()

t.pencolor("black")
t.forward(125)
t.penup()
t.right(135)
t.pendown()
t.forward(175)
t.right(90)
t.forward(175)
t.right(135)
t.forward(125)

t.fillcolor("red2")
t.begin_fill()
t.penup()
t.right(90)
t.forward(0)
t.pendown()
t.right(315)
t.forward(20)
t.left(315)
t.forward(75)
t.right(45)
t.forward(20)
t.right(90)
t.forward(20)
t.right(45)
t.forward(75)
t.right(45)
t.forward(20)
t.end_fill()



#t.end_fill()    #Finish filling
