import pygame
import os
import random


if __name__ == "__main__":
    music_dirs = []
    root_dir = 'music'  # 相对根目录
    types = os.listdir(root_dir)  # 歌曲分类文件名
    for typ in types:
        for root, dirs, files in os.walk(os.path.join(root_dir, typ)):
            music_list = []  # 每种类型的歌曲放一个列表
            for file in files:
                music_list.append(os.path.join(root, file))  # 歌曲完整路径
            music_list.pop(-1)  # 去掉txt
            music_dirs.append(music_list)  # 存到大列表
    # print(music_dirs)

    try:
        while True:
            feeling = int(input('你现在的心情是(0: 高兴, 1:伤心): '))
            music_dir = random.choice(music_dirs[feeling])
            # print(music_dirs[feeling])
            music_name = music_dir.rsplit("\\", 1)[1]  # 从路径里切出歌曲名字

            print(f'根据您的心情为您点歌: {music_name}')
            pygame.mixer.init()
            pygame.mixer.music.load(music_dir)
            pygame.mixer.music.play()

            opr = input('(8: 停止播放并继续    其他字符: 退出)\n')
            pygame.mixer.music.stop()
            if opr.strip() != '8':
                break
    except ValueError:
        print('输入有误')
