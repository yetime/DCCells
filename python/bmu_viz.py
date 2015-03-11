#!/usr/bin/python

import sys, os, random
import numpy as np
import xml.dom.minidom as xmml
import pygame
import time

if (len(sys.argv) !=5):
  print ("Usage: gengif.py from_xmml to_xmml scale timesteps")
  quit()

DCC_COLOUR=(204,0,204)
OC_COLOUR=(51,255,255)
OB_COLOUR=(102,255,102)
BMU_COLOUR=(255,255,0)


worldsize=0 
scale=float(sys.argv[3])
xmmltree=xmml.parse("../Data/0.xml")
for env in xmmltree.getElementsByTagName('worldsize'):
        worldsize=int(env.firstChild.nodeValue)

pygame.init()
screen=pygame.display.set_mode((int(worldsize*scale),int(worldsize*scale))) 
myfont = pygame.font.SysFont("monospace", 20)
clock=pygame.time.Clock() 
pause=False;


xmmls=range(int(sys.argv[1]), int(sys.argv[2])+1, int(sys.argv[4])) 
for x in xmmls:
    screen.fill((0,0,0))
    xmmlfile="../Data/"+str(x)+".xml"
    print(xmmlfile)
    xmmltree=xmml.parse(xmmlfile)
    

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
	    geo=(geo[1:len(geo)-1]).split(",");
	    posx=float(geo[0])*scale+10;
            posy=float(geo[1])*scale+10;
	    z=agent.getElementsByTagName("z")[0].firstChild.nodeValue
	    rects_bmu.append([posx,posy,1,z])
       
    	for r in rects_dcc:
            pygame.draw.circle(screen,DCC_COLOUR,(int(r[0]), int(r[1])),int(r[2]))
    	for r in rects_ob:
            pygame.draw.circle(screen,OB_COLOUR,(int(r[0]), int(r[1])),int(r[2]))
    	for r in rects_oc:
       	    pygame.draw.circle(screen, OC_COLOUR, (int(r[0]), int(r[1])),int(r[2]))  
    	for r in rects_bmu:
            pygame.draw.circle(screen,BMU_COLOUR,(int(r[0]), int(r[1])),int(r[2]))    
	    zlabel=myfont.render("Z: " + str(round(float(r[3]),1)), 1, BMU_COLOUR, (0,0,0))
	    screen.blit(zlabel, (int(r[0]),int(r[1])));
	    
    
    
    	#Draw other stuff such as the time label and a scale bar
    	label = myfont.render("Time: " + str(x/24) +" d " + str(x%24) +" h", 1, (255,255,255))
    	screen.blit(label, (10, 10))
	
	label_ob=myfont.render("OB: " + str(len(rects_ob)), 1, OB_COLOUR, (0,0,0))
	screen.blit(label_ob, (10,worldsize*scale-50))
	label_oc=myfont.render("OC: " + str(len(rects_oc)), 1, OC_COLOUR, (0,0,0))
	screen.blit(label_oc, (10,worldsize*scale-25))
    	
    
    	start_line= worldsize * scale - 1100*scale;
    	end_line=worldsize *scale - 100*scale; 
    
    	pygame.draw.line(screen, (255,255,255),(start_line,10), (end_line,10), 10);
    
    	label2 = myfont.render("Scale: 1 mm", 1, (255,255,255))
    	screen.blit(label2, (start_line, 20)) 
	
        if  pause == False:
            for event in pygame.event.get():
	        if event.type==pygame.KEYUP:
		    if event.key==pygame.K_p:
	                pause = True
		    if event.key==pygame.K_q:
		    	pygame.quit()
			sys.exit()
   		    
	
        while pause == True:
	    time.sleep(0.1);
	    for event in pygame.event.get():
	        if event.type==pygame.KEYUP:
	            if event.key==pygame.K_p:
		        pause = False;
		    if event.key==pygame.K_q:
		    	pygame.quit()
			sys.exit()
			
    time.sleep(0.1)
    pygame.display.flip() 
pygame.quit()    
