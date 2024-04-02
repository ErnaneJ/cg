# Sobel Gradient 3x3

For the given image:

```cpp
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 1 0 0 0 0
0 0 0 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 1 0 0
0 0 1 1 1 1 1 1 1 1 0 0
0 0 1 1 1 1 1 1 1 1 0 0
0 0 0 1 1 1 1 1 1 1 0 0
0 0 0 0 1 1 1 1 1 0 0 0
0 0 0 0 0 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
```

The following results are obtained when applying the Sobel 3x3 gradient filter:

| Original Image | Gradient Image |
|:--------------:|:--------------:|
|![image](./images/image.png)|![grad](./images/grad.png)|
|![grad_x](./images/grad_x.png)|![grad_y](./images/grad_y.png)|
|![abs_grad_x](./images/abs_grad_x.png)|![abs_grad_y](./images/abs_grad_y.png)|

However, performing the same experiment for a larger image can yield more visually interesting results.

| Original Image | Gradient Image |
|:--------------:|:--------------:|
|![image](./images/image-400x400.png)|![grad](./images/grad-400x400.png)|
|![grad_x](./images/grad_x-400x400.png)|![grad_y](./images/grad_y-400x400.png)|
|![abs_grad_x](./images/abs_grad_x-400x400.png)|![abs_grad_y](./images/abs_grad_y-400x400.png)|