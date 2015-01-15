#!/usr/bin/python

import sys, os, random
import numpy as np
import xml.dom.minidom as xmml
import pygame
import time

if (len(sys.argv) !=4):
  print ("Usage: gengif.py from_xmml to_xmml scale")
  quit()

DCC_COLOUR=(204,0,204)
OC_COLOUR=(51,255,255)
OB_COLOUR=(102,255,102)
BMU_COLOUR=(255,255,0)

#should loop through all files here... to let it walk

worldsize=0 
scale=float(sys.argv[3])
xmmltree=xmml.parse("../0.xml")
for env in xmmltree.getElementsByTagName('worldsize'):
        worldsize=int(env.firstChild.nodeValue)

pygame.init()
screen=pygame.display.set_mode((int(worldsize*scale),int(worldsize*scale))) 
clock=pygame.time.Clock()

xmmls=range(int(sys.argv[1]), int(sys.argv[2])+1)
for x in xmmls:
    xmmlfile="../"+str(x)+".xml"
    print(xmmlfile)
    xmmltree=xmml.parse(xmmlfile)
    

   

#for env in xmmltree.getElementsByTagName('unitum'):
#    unitum=int(env.firstChild.nodeValue)
    


    rects_dcc=[]
    rects_oc=[]
    rects_ob=[]
    rects_bmu=[]

    for agent in xmmltree.getElementsByTagName('xagent'):
        name=agent.getElementsByTagName("name")[0].firstChild.nodeValue 
        if name=="oc":
	   
            geo=agent.getElementsByTagName("oc_dim")[0].firstChild.nodeValue  
            geometry=(geo[2:len(geo)-1]).split(",")  
            radius=float(geometry[2])*scale/2;
            posx=float(geometry[0])*scale+radius;
            posy=geometry[1];
	    
	    posy=posy[1:len(posy)-1];
	    
	    posy=float(posy)*scale+radius;  
	 
            #rects_oc.append(pygame.Rect(posx, posy, width, width))
            rects_oc.append([posx,posy,radius])
	if name=="ob":
	   
            geo=agent.getElementsByTagName("ob_dim")[0].firstChild.nodeValue  
            geometry=(geo[2:len(geo)-1]).split(",")  
            radius=float(geometry[2])*scale/2;
            posx=float(geometry[0])*scale+radius;
            posy=geometry[1];
	    
	    posy=posy[1:len(posy)-1];
	    
	    posy=float(posy)*scale+radius;  
	 
            #rects_oc.append(pygame.Rect(posx, posy, width, width))
            rects_ob.append([posx,posy,radius]);
	if name=="bmu":
	    geo=agent.getElementsByTagName("bmu_position")[0].firstChild.nodeValue
	    print("GEO: "+geo);
	    geo=(geo[1:len(geo)-1]).split(",");
	    posx=float(geo[0])*scale+10;
            posy=float(geo[1])*scale+10;
	    print("X: "+str(posx)+" Y: "+str(posy));
	    rects_bmu.append([posx,posy,10])
	    
    done=False
    
    #while not done:
    #	for event in pygame.event.get():
    #        if event.type==pygame.QUIT:
    #            done=True
    screen.fill((0,0,0))
    for r in rects_bmu:
        pygame.draw.circle(screen,BMU_COLOUR,(int(r[0]), int(r[1])),int(r[2]))
    for r in rects_dcc:
        pygame.draw.circle(screen,DCC_COLOUR,(int(r[0]), int(r[1])),int(r[2]))
    for r in rects_ob:
        pygame.draw.circle(screen,OB_COLOUR,(int(r[0]), int(r[1])),int(r[2]))
    for r in rects_oc:
            #pygame.draw.rect(screen,OC_COLOUR, r)
        pygame.draw.circle(screen, OC_COLOUR, (int(r[0]), int(r[1])),int(r[2]))
        #print(r[0], r[1]);    
	#time.sleep(0.01);    
    pygame.display.flip()
    print(next)
pygame.quit()    
