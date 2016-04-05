//Program Name : Tacey's 2048(A Clone Of 2048)
//Author : Tacey Wong

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>


bool board[4][4] = {{0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}};


#С��ĳߴ�
const int box_size = 50
#С�����
const int box_gap  = 10
#���ڵĶ���
const int top_of_screen = 200
#���ڵĵײ�
const int bottom_of_screen = 60
#���ڵ���
const int left_of_screen = 40
#���������� = 4��С��+5�����+������Ե
const int screen_width  = box_size * 4 + box_gap * 5 + left_of_screen * 2
#��������߶� = �ϱ߲���+5�����+4��С��+���沿��+һ����Ե
const int screen_height = top_of_screen + box_gap * 5 + box_size * 4 + left_of_screen + bottom_of_screen

#�������ڣ�������ʾģʽ,���ô��ڱ���
sf::RenderWindow window(sf::VideoMode(screen_width, screen_height, 32), "Tacey's 2048",
                            sf::Style::Titlebar | sf::Style::Close);
window.setVerticalSyncEnabled(true);

score = 0

#����Color����
#				R   G   B
sf::Color OLDLACE     (253,245,230);
sf::Color IVORY       (205,245,230);
sf::Color BLACK       (  0,  0,  0);
sf::Color RED         (255,  0,  0);
sf::Color RED2        (238,  0,  0);
sf::Color DARKGOLD    (255,185, 15);
sf::Color GOLD        (255,215,  0);
sf::Color GRAY        (105,105,105);
sf::Color CHOCOLATE   (210,105, 30);
sf::Color CHOCOLATE1  (255,127, 36);
sf::Color CORAL       (255,127, 80);
sf::Color CORAL2      (238,106, 80);
sf::Color ORANGED     (255, 69,  0);
sf::Color ORANGED2    (238, 64,  0);
sf::Color DARKORANGE  (255,140,  0);
sf::Color DARKORANGE2 (238,118,  0);
sf::Color FORESTGREEN ( 34,139, 34);

//��ɫ����







//С����
class Box//���ʼ������
{
public :
    Box();
    Box(int topleft_x,int topleft_y,string &str ,sf::Color &cl);
private:
    int topleft_x;
    int topleft_y;#С�����Ͻ�����
    string text;#С���ı��ַ���
    sf::Color color;#С��������ɫ
    sf::RectangleShape leftPaddle;
#�����Ⱦ����
void render(surface):
        pygame.draw.rect(surface, self.color, (x, y, box_size, box_size)) #���ƾ���
        text_height  = int(box_size * 0.35)  //С���ı��߶�����ΪС��ߴ��0.35������ǿ��ת��Ϊ����
        font_obj     = pygame.font.Font("freesansbold.ttf", text_height) #�������
        text_surface = font_obj.render(self.text, True, BLACK)  # �ı���Ⱦ��
        text_rect    = text_surface.get_rect()		#�ı���������
        text_rect.center = (x + box_size / 2, y + box_size / 2) #�ı������������������
        surface.blit(text_surface, text_rect) #�����ı�

};



//С����ƺ���
void draw_box():

    //��ɫ����
    const int colors = {0:GRAY, 2:(239, 233, 182), 4:(239, 228, 151), 8:(243, 212, 77), 16:(239, 206, 25),
               32:(242, 157, 12), 64:(214, 214, 42), 128:(239, 207, 108), 256:(239, 207, 99),
               512:(239, 203, 82), 1024:(239, 199, 57), 2048:(239, 195, 41), 4096:(255, 60, 57)}
    #colors = {0:(192, 192, 192), 2:(176, 224, 230), 4:(127, 255, 212), 8:(135, 206, 235), 16:(64, 224, 208),
     #         32:(0, 255, 255), 64:(0, 201, 87), 128:(50, 205, 50), 256:(34, 139, 34),
      #        512:(0, 255, 127), 1024:(61, 145, 64), 2048:(48, 128, 20), 4096:(65, 105, 255),
       #       8192:(8, 46, 84), 16384:(11, 23, 70), 32768:(25, 25, 112), 65536:(0, 0, 255)}

    #С����������Ͻ�����
    x, y = left_of_screen, top_of_screen
    #С������ĳߴ�
    size = box_size * 4 + box_gap * 5
    #���ƾ���
   	#pygame.draw.rect(screen, BLACK, (x, y, size, size))
    #��һ��С������Ͻ�����
    x, y = x + box_gap, y + box_gap
    for i in range(4):
        for j in range(4):
            idx = board[i][j]
            #�����С��ֵ��ʶ�����ı�Ϊ���ַ����������ı�Ϊidxֵ
            if idx == 0:
                text = ""
            else:
                text = str(idx)
           	#if idx > 65536: idx = 65536
           	#���ø�С����ɫ
            color = colors[idx]
            #����box����ʵ��
            box = Box((x, y), text, color)
            #
            box.render(screen)
            #����x��ֵ��ʾ��һ��С������Ϻ�����
            x += box_size + box_gap
        x = left_of_screen + box_gap
        y += box_size + box_gap

#����������ֵĺ���
void set_random_number()
	#�洢�пյ�С��
    pool = []
    for i in range(4):
        for j in range(4):
            if board[i][j] == 0:
                pool.append((i, j))
    #���пյ�С�������ѡȡһ��
    m = random.choice(pool)
    #�ӿճ��н����ѡ����С��ɾȥ
    pool.remove(m)
    #������� 2 �� 4 ������ 1 ��
    value = random.uniform(0, 1)
    if value < 0.1:
        value = 4
    else:
        value = 2
    board[m[0]][m[1]] = value

#��ʼ�����棬
def init_board():
    for i in range(2):
        set_random_number()

#�߼���������
def combinate(L):

    ans = [0, 0, 0, 0]
    num = []
    for i in L:
        if i != 0:
            num.append(i)
    length = len(num)
    if length == 4:
        if num[0] == num[1]:
            ans[0] = num[0] + num[1]
            score += ans[0]
            if num[2] == num[3]:
                ans[1] = num[2] + num[3]
                score += ans[1]
            else:
                ans[1] = num[2]
                ans[2] = num[3]
        elif num[1] == num[2]:
            ans[0] = num[0]
            ans[1] = num[1] + num[2]
            ans[2] = num[3]
            score += ans[1]
        elif num[2] == num[3]:
            ans[0] = num[0]
            ans[1] = num[1]
            ans[2] = num[2] + num[3]
            score += ans[2]
        else:
            for i in range(length):
                ans[i] = num[i]
    elif length == 3:
        if num[0] == num[1]:
            ans[0] = num[0] + num[1]
            ans[1] = num[2]
            score += ans[0]
        elif num[1] == num[2]:
            ans[0] = num[0]
            ans[1] = num[1] + num[2]
            score += ans[1]
        else:
            for i in range(length):
                ans[i] = num[i]
    elif length == 2:
        if num[0] == num[1]:
            ans[0] = num[0] + num[1]
            score += ans[0]
        else:
            for i in range(length):
                ans[i] = num[i]
    elif length == 1:
        ans[0] = num[0]
    else:
        pass
    return ans

def left():
    for i in range(4):
        temp = combinate(board[i])
        for j in range(4):
            board[i][j] = temp[j]
            # score += temp[1]
    # return score


def right():
    # global score
    for i in range(4):
        temp = combinate(board[i][::-1])
        for j in range(4):
            board[i][3-j] = temp[j]
            # score += temp[1]
    # return score

def up():
    for i in range(4):
        to_comb = []
        for j in range(4):
            to_comb.append(board[j][i])
        temp = combinate(to_comb)
        for k in range(4):
            board[k][i] = temp[k]
            # score += temp[1]
    # return score

def down():
    for i in range(4):
        to_comb = []
        for j in range(4):
            to_comb.append(board[3-j][i])
        temp = combinate(to_comb)
        for k in range(4):
            board[3-k][i] = temp[k]
            # score += temp[1]
    # return score

def write(msg="pygame is cool", color= BLACK, height = 14):
    #myfont = pygame.font.SysFont("None", 32) #To avoid py2exe error
    myfont = pygame.font.Font("freesansbold.ttf", height)
    mytext = myfont.render(msg, True, color)
    mytext = mytext.convert_alpha()
    return mytext
#�ж���Ϸ�Ƿ���������� 2��
def is_over():
    ### if 0 in board
    for i in range(4):
        for j in range(4):
            if board[i][j] == 0:
                return False

    for i in range(4):
        for j in range(3):
            if board[i][j] == board[i][j+1]:
                return False

    for i in range(3):
        for j in range(4):
            if board[i][j] == board[i+1][j]:
                return False

    return True

def read_best():
    try:
        f = open('best.rec', 'r')
        best = int(f.read())
        f.close()
    except:
        best = 0
    return best

def write_best(best):
    try:
        f = open('best.rec', 'w')
        f.write(str(best))
        f.close()
    except IOError:
        pass

int main(void)
{

    #ȫ�ֱ���score
    global score
    #screen.blit(background, (0, 0))
    #��ʼ������
    init_board()
    #�������
    newboard = deepcopy(board)
    #�ж���Ϸ�Ƿ����
    gameover = is_over()


    #����С��
    draw_box()
    #���ƴ��ڵ��ϲ���
    screen.blit(write("2048", height = 40, color = GOLD), (left_of_screen, left_of_screen // 2))
    screen.blit(write("SCORE", height=14, color=FORESTGREEN), (left_of_screen+105, left_of_screen//2 + 5))
    rect1 = pygame.draw.rect(screen, FORESTGREEN, (left_of_screen+100, left_of_screen//2 + 30, 60, 20))
    text1 = write(str(score), height=14, color=GOLD)
    text1_rect = text1.get_rect()
    text1_rect.center = (left_of_screen+100+30, left_of_screen//2 + 40)
    screen.blit(text1, text1_rect)

    screen.blit(write("BEST", height=14, color=FORESTGREEN), (left_of_screen+175, left_of_screen//2 + 5))
    rect2 = pygame.draw.rect(screen, FORESTGREEN, (left_of_screen+165, left_of_screen//2 + 30, 60, 20))
    best = read_best()
    #��ȫ����Ҫ
    if best < score:
        best = score
    text2 = write(str(best), height=14, color=GOLD)
    text2_rect = text2.get_rect()
    text2_rect.center = (left_of_screen+165+30, left_of_screen//2 + 40)
    screen.blit(text2, text2_rect)


    screen.blit(write("Use LEFT, RIGHT, UP, DOWN", height=16, color=GRAY), (left_of_screen, screen_height - bottom_of_screen))
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // �رմ��� �� Esc�� ���˳�
            if ((event.type == sf::Event::Closed) ||
               ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }



        }
        for event in pygame.event.get():
            if event.type == QUIT or (event.type == KEYUP and event.key == K_ESCAPE):
                write_best(best)
                pygame.quit()
                exit()
            elif not gameover:
                if event.type == KEYUP and event.key == K_UP:
                    up()
                elif event.type == KEYUP and event.key == K_DOWN:
                    down()
                elif event.type == KEYUP and event.key == K_LEFT:
                    left()
                elif event.type == KEYUP and event.key == K_RIGHT:
                    right()
                if newboard != board:
                    set_random_number()
                    newboard = deepcopy(board)
                    draw_box()
                #�Ƿ�Ҫ��������������������
                gameover = is_over()

                rect1 = pygame.draw.rect(screen, FORESTGREEN, (left_of_screen+100, left_of_screen//2 + 30, 60, 20))
                text1 = write(str(score), height=14, color=GOLD)
                text_rect = text1.get_rect()
                text_rect.center = (left_of_screen+100+30, left_of_screen//2 + 40)
                screen.blit(text1, text_rect)

                rect2 = pygame.draw.rect(screen, FORESTGREEN, (left_of_screen+165, left_of_screen//2 + 30, 60, 20))
                if best < score:
                    best = score
                text2 = write(str(best), height=14, color=GOLD)
                text2_rect = text2.get_rect()
                text2_rect.center = (left_of_screen+165+30, left_of_screen//2 + 40)
                screen.blit(text2, text2_rect)

            else:
                write_best(best)
                screen.blit(write("Game Over!", height = 40, color = FORESTGREEN), (left_of_screen, screen_height // 2))


         window.display();
    }

    return EXIT_SUCCESS;
}



