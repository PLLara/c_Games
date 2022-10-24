#include <stdio.h>

char isOpositeAngle(int angle, int otherAngle)
{
    if (angle == (otherAngle + 180))
    {
        return 1;
    }
    if (angle == (otherAngle - 180))
    {
        return 1;
    }

    return 0;
}


int main(){
    printf("%d\n",isOpositeAngle(0,180));

    printf("%d\n",isOpositeAngle(27,207));

    printf("%d\n",isOpositeAngle(180,360));

    printf("%d\n",isOpositeAngle(200,20));
}

