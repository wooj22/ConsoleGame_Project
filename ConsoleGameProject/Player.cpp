#include "Player.h"
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"
#include "GameManager.h"

// 생성자
Player::Player(int x, int y)
    : hp(100), damage(10), speed(1), posX(x), posY(y), velocityY(0.0f), isGrounded(false) {
}

// 위치 관련 함수
int Player::GetPosX() const { return posX; }
int Player::GetPosY() const { return posY; }

// 체력 관련 함수
int Player::GetHp() const { return hp; }
void Player::Damaged(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
}

// 이동 처리
void Player::PlayerMove(int direction) {
    if (direction == -1 && CanMove(posX - speed, posY)) posX -= speed; // 왼쪽 이동
    if (direction == 1 && CanMove(posX + speed, posY)) posX += speed;  // 오른쪽 이동
}

// 점프 처리
void Player::PlayerJump() {
    if (isGrounded) {
        velocityY = -3.5f; // 점프 힘
        isGrounded = false;
    }
}

// 중력 적용
void Player::ApplyGravity() {
    if (!isGrounded) {
        velocityY += 0.2f; // 중력 가속도
        if (velocityY > 5.0f) velocityY = 5.0f; // 최대 낙하 속도 제한
    }

    int nextY = posY + (int)velocityY;
    if (CanMove(posX, nextY)) {
        posY = nextY;
    }
    else {
        velocityY = 0;
        isGrounded = true;
    }
}

// 충돌 감지
bool Player::CanMove(int x, int y) const {
    //return floor1StaticMap[y][x] != L'▓';
    return true;
}
