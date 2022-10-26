import cv2

path = "C:\D\subject\Programming1\\10421104\images\\foreground.jpg"

img1 = cv2.imread(path)

print(img1.shape)

cv2.imwrite("foreground.jpg", img1)

path = "C:\D\subject\Programming1\\10421104\images\\background.jpg"

img2 = cv2.imread(path)

print(img2.shape)

cv2.imwrite("background.jpg", img2)
