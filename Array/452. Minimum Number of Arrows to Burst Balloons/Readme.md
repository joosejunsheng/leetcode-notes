## 452. Minimum Number of Arrows to Burst Balloons
In order to pop all the balloons with the least number of arrows, every single arrow need to burst as many balloons as possible.

How to start?
The very first balloon we need to pop is always the on with the least xStart, which is the balloon at the first position. We need to rearrange the balloons **(Sort them)**.
This gives us an idea of **AT MOST** how many arrows we need to use to pop all the balloons if we pop them 1 by 1.

**First Balloon: [1,6] - Starts at 1, ends at 6**
We can pick between 1 to 6 to shoot, but which position do we need to shoot at? We try to be greedy and shoot at the last position, so we were hoping that it shoots any other overlapped balloons at the same time.

***What happen if we have a second balloon which is [1,3]?***
If we shoot our arrow at 6th position on our first balloon which is [1,6], we might need another arrow to make sure [1,3] pops.

So instead of sorting based on balloons xStart, we sort by balloons xEnd so [1,3] will be arranged infront of [1,6].

Now it works if we just pick the last position of every unpopped balloons!!!