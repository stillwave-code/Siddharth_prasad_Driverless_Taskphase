import pandas as pd

df=pd.read_csv("cone_id.csv")

df['dist']=df['x']**2+df['y']**2
df=df.sort_values('dist')
df=df.drop(columns=['dist'])

blue_cones=df[df['colour']=="blue"]
yellow_cones=df[df['colour']=="yellow"]

blue_cones.to_csv('blue_cones.csv', index=False)
yellow_cones.to_csv('yellow_cones.csv', index=False)

n=len(blue_cones)
midpoints=[]
for i in range(n):
        blue=blue_cones.iloc[i]
        #print(blue)

        b_x=blue['x']
        b_y=blue['y']

        distance=(yellow_cones['x']-b_x)**2+(yellow_cones['y']-b_y)**2

        
        closest_row_number = distance.idxmin()
    
      
        closest_yellow = yellow_cones.loc[closest_row_number]
    
        mid_x = (b_x + closest_yellow['x']) / 2
        mid_y = (b_y + closest_yellow['y']) / 2
    

        midpoints.append( [mid_x, mid_y])

#print(midpoints)
centreline=pd.DataFrame(midpoints,columns=['x','y'])
centreline.to_csv("centreline.csv",index=False)
