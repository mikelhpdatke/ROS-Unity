import cv2
import numpy as np


class Warper:
    def __init__(self):
        # src = np.float32([
        #     [409, 504],
        #     [760, 504],
        #     [1000, 689],
        #     [189, 689],
        # ])

        # dst = np.float32([
        #     [350, 0],
        #     [850, 0],
        #     [850, 720],
        #     [350, 720],
        # ])

        src = np.float32([
            [106, 160],
            [212, 160],
            [320, 240],
            [0, 240],
        ])

        dst = np.float32([
            [80, 106],
            [160, 106],
            [160, 320],
            [80, 320],
        ])

        self.M = cv2.getPerspectiveTransform(src, dst)
        self.Minv = cv2.getPerspectiveTransform(dst, src)

    def warp(self, img):
        return cv2.warpPerspective(
            img,
            self.M,
            (img.shape[0], img.shape[1]),
            flags=cv2.INTER_LINEAR
        )

    def unwarp(self, img):
        return cv2.warpPersective(
            img,
            self.Minv,
            (img.shape[1], img.shape[0]),
            flags=cv2.INTER_LINEAR
        )