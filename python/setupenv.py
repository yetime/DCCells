#!/usr/bin/python

import sys, os, random
import numpy as np

SIZE_OC=180
SIZE_OB=20
SIZE_DCC=20

OC=[]
OB=[]
DCC=[]

worldsize=int(sys.argv[2])
world=np.zeros((worldsize,worldsize), dtype=int)

#Tries to find unoccupied random placements for number cells of type celltype.
def findplacement(celltype, number):
    collisions=[]
    col=False
    size=SIZE_OC
    if(celltype==2): size=SIZE_OB
    if(celltype==3): size=SIZE_DCC
    
    for i in range(number):
        upperlimit=worldsize-size 
        positionx=random.randint(0,upperlimit)
        positiony=random.randint(0,upperlimit) 
        col=False
        #checking if there is enough space for one cell
        for k in range(positionx, positionx+size):
            for l in range(positiony, positiony+size):
                if world[k][l]!=0: col=True  
        if col==True:
            collisions.append([positionx,positiony])
        #if there is enough space and no collision occurs, 
        #mark the occupied fields in the world matrix
        if col==False:
            for k in range(positionx, positionx+size):
                for l in range(positiony,positiony+size): 
                    world[k][l]=celltype
            if(celltype==3):
                DCC.append([positionx,positiony])        
            if(celltype==2):
                OB.append([positionx,positiony])
            if(celltype==1):
                OC.append([positionx,positiony])
                
    solved=False
    if collisions==[]: solved=True
    
    #deal with the collisions
    for i in collisions:
        
        j=i[0]
        k=i[1]
    #try to find alternate spot by adding random displacements in x and y
        while world[j,k]!=0:
            j=j+random.randint(-1,1)
            k=k+random.randint(-1,1)
            #ups, we ran over the boundaries of our world
            if(j+size>worldsize): j=0
            if(k+size>worldsize): k=0
            if world[j+size,k]==0 and world[j,k+size]==0 and world[j+size, k+size]==0 and (j+size)<worldsize and (k+size)<worldsize:
                squarefree=True
                for p in range(j,j+size):
                    for q in range(k,k+size):
                        if world[p,q]!=0:
                            squarefree=False
                if squarefree==True: solved=True
                break
            if(celltype==3):
                DCC.append([j,k])
            if(celltype==2):
                OB.append([j,k])
            if(celltype==1):
                OC.append([j,k])
            for p in range(j, j+size):
                for q in range(k,k+size): 
                    world[p][q]=celltype
    
    if solved==False:
        print("Collisions couldn't be resolved, change size of world or number of cells")



if (len(sys.argv) !=7):
  print ("Usage: setupenv.py outfile worldsize n_ob n_oc n_dcc clustered")
  quit()
  
outfile=open(sys.argv[1],'w')

outfile.write("<?xml version=\"1.0\" encoding=\"UTF-8\"?> \n")
outfile.write("<states>\n")
outfile.write("<itno>0</itno>\n\n")


if(sys.argv[6]=="0"):  
    findplacement(1,int(sys.argv[3]))
    findplacement(2,int(sys.argv[4]))
    findplacement(3,int(sys.argv[5]))
                    
outfile.write("<environment>\n")
outfile.write("    <worldsize>"+str(worldsize)+"</worldsize>\n")
outfile.write("    <unitum>1</unitum>\n")
outfile.write("    <oc_speed>10</oc_speed>\n")
outfile.write("</environment>\n\n")
outfile.write("<agents>")
for i in range(len(OC)):
    outfile.write("<xagent>\n")
    outfile.write("    <name>oc</name>\n")
    outfile.write("    <id>OC"+str(i)+"</id>\n")
    outfile.write("    <geo>{"+str(OC[i][0])+","+str(OC[i][1])+","+str(SIZE_OC)+"}</geo>\n")
    outfile.write("</xagent>\n")

for i in range(len(OB)):
    outfile.write("<xagent>\n")
    outfile.write("<name>ob</name>\n")
    outfile.write("    <id>OB_"+str(i)+"</id>\n")
    outfile.write("    <geo>{"+str(OB[i][0])+","+str(OB[i][1])+","+str(SIZE_OB)+"}</geo>\n")
    outfile.write("</xagent>\n")
    
for i in range(len(DCC)):
    outfile.write("<xagent>\n")
    outfile.write("    <name>dcc</name>\n")
    outfile.write("    <id>DCC_"+str(i)+"</id>\n")
    outfile.write("    <geo>{"+str(DCC[i][0])+","+str(DCC[i][1])+","+str(SIZE_DCC)+"}</geo>\n")
    outfile.write("</xagent>\n")

outfile.write("<xagent>\n")
outfile.write("    <name>pointsource</name>\n")
outfile.write("    <id>ps0</id>\n")
outfile.write("    <descrip>{1,1,10,100,100,0.01,3,0}</descrip>\n")
outfile.write("    <active>1</active>\n")
outfile.write("    <source_start>1</source_start>\n")
outfile.write("    </xagent>\n")
outfile.write("</agents>\n")
outfile.write("</states>")
outfile.close()

#for i in range(worldsize):
#    for j in range(worldsize):
#        if world[i,j]==0 : print("0"),
#        else: print("1"),
#    print("")



