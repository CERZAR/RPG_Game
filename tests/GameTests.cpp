//
// Created by cezar on 06.02.2020.
//

#include "../Packages/googletest/googletest/include/gtest/gtest.h"

#include "../Headers/Player.h"
#include "../Headers/Random.h"
#include "../Headers/Map.h"
#include "../Headers/GreenJelly.h"

ResourcesContainer res;
Player player(&res);

TEST(GameTests, playerUpdateStatsTest)
{
    EXPECT_EQ(1, player.level);
    EXPECT_EQ(10, player.maxHP);
    EXPECT_EQ(10, player.maxMP);
    EXPECT_EQ(1.f, player.movementSpeed);
    EXPECT_EQ(1, player.damage);
    EXPECT_EQ(4, player.needExp);
    EXPECT_EQ(0, player.coins);
    EXPECT_EQ(0, player.exp);
    player.level = 4;
    EXPECT_NE(5, player.level);
    player.exp += 4;
    player.update();
    EXPECT_EQ(5, player.level);
    player.updateStats();
    EXPECT_EQ(14, player.maxHP);
    EXPECT_EQ(30, player.maxMP);
    EXPECT_EQ(2.f, player.movementSpeed);
    EXPECT_EQ(2, player.damage);
    EXPECT_EQ(30, player.needExp);
    EXPECT_EQ(0, player.coins);
    EXPECT_EQ(0, player.exp);
};

TEST(GameTests, playerUpdatePositionTest)
{
    player.rect.setPosition(25.f, 25.f);
    player.rect.move(1.f,1.f);
    EXPECT_EQ(sf::Vector2f(26.f, 26.f),  player.rect.getPosition());
}

TEST(GameTests, mapCollisionTest)
{
    Map map(&res);
    map.createMap();
    player.rect.setPosition(25.f, 25.f);
    EXPECT_TRUE(map.checkCollision(player.rect));
    player.rect.setPosition(51.f, 51.f);
    EXPECT_FALSE(map.checkCollision(player.rect));
}

TEST(GameTests, PlayerEnemyCollisionTest)
{
    std::vector<Enemy*>::const_iterator enemy_iter;
    std::vector<Enemy*> enemiesArray;

    Enemy* enemy = new GreenJelly(&res);
    enemy->rect.setPosition(500.f, 500.f);
    enemy->hp = 1;
    enemiesArray.push_back(enemy);

    enemy = new GreenJelly(&res);
    enemy->rect.setPosition(800.f, 800.f);
    enemiesArray.push_back(enemy);

    player.rect.setPosition(enemiesArray[0]->rect.getPosition());

    // Player & enemies collision
    int counter;
    counter = 0;
    for (enemy_iter = enemiesArray.begin(); enemy_iter != enemiesArray.end(); enemy_iter++)
    {
            if (player.rect.getGlobalBounds().intersects(enemiesArray[counter]->rect.getGlobalBounds()))
            {
                if (!enemiesArray[counter]->isAgro)
                {
                    enemiesArray[counter]->isAgro = true;
                    enemiesArray[counter]->movementSpeed *= 1.5;
                }
                player.hp -= enemiesArray[counter]->damage;
                enemiesArray[counter]->hp -= player.damage;
            }
            counter++;
    }
    EXPECT_EQ(10, player.hp);
    EXPECT_TRUE(enemiesArray[0]->isAgro);

    // Update enemies
    counter = 0;
    for (enemy_iter = enemiesArray.begin(); enemy_iter != enemiesArray.end(); enemy_iter++)
    {
        enemiesArray[counter]->update(static_cast<int>(player.rect.getPosition().x), static_cast<int>(player.rect.getPosition().y));
        counter++;
    }
    EXPECT_FALSE(enemiesArray[0]->isExist);

    // Deleting enemies
    counter = 0;
    for (enemy_iter = enemiesArray.begin(); enemy_iter != enemiesArray.end(); enemy_iter++)
    {
        if (!enemiesArray[counter]->isExist)
        {
            player.exp += enemiesArray[counter]->getExp;
            enemiesArray.erase(enemy_iter);
            break;
        }
        counter++;
    }
    EXPECT_EQ(1, enemiesArray.size());
    EXPECT_EQ(2, player.exp);
}

TEST(GameTests, weaponUpgrateTest)
{
    player.currentWeapon->updateLevel();
    player.currentWeapon->update();
    player.currentWeapon->updateStats();
    EXPECT_EQ(900, player.currentWeapon->atackSpeed);
    EXPECT_EQ(20, player.currentWeapon->upgateCost);
    EXPECT_EQ(2, player.currentWeapon->damage);
    EXPECT_EQ(4.f, player.currentWeapon->speed);
    EXPECT_EQ(5000000, player.currentWeapon->lifetime);
}