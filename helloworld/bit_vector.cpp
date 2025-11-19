#include <stdio.h>
#include <stdbool.h>

// 用8位无符号整数表示课程集合（最多8门课）
typedef unsigned char CourseSet;

// 课程名称数组
const char* courses[] = {"数学", "物理", "化学", "生物", "历史", "地理", "英语", "体育"};

// 函数声明
CourseSet create_empty_set();
void add_course(CourseSet* set, int course_id);
void remove_course(CourseSet* set, int course_id);
bool has_course(CourseSet set, int course_id);
void print_courses(CourseSet set);
CourseSet union_sets(CourseSet set1, CourseSet set2);
CourseSet intersection_sets(CourseSet set1, CourseSet set2);
CourseSet difference_sets(CourseSet set1, CourseSet set2);

int main() {
    // 测试代码
    CourseSet student1 = create_empty_set();
    CourseSet student2 = create_empty_set();
    
    // 学生1选课：数学(0), 化学(2), 英语(6)
    add_course(&student1, 0);
    add_course(&student1, 2);
    add_course(&student1, 6);
    
    // 学生2选课：物理(1), 化学(2), 历史(4), 体育(7)
    add_course(&student2, 1);
    add_course(&student2, 2);
    add_course(&student2, 4);
    add_course(&student2, 7);
    
    printf("学生1的选课: ");
    print_courses(student1);
    
    printf("学生2的选课: ");
    print_courses(student2);
    
    // 集合运算
    printf("两人都选的课程: ");
    print_courses(intersection_sets(student1, student2));
    
    printf("所有的选课: ");
    print_courses(union_sets(student1, student2));
    
    printf("学生1选了但学生2没选的课程: ");
    print_courses(difference_sets(student1, student2));
    
    return 0;
}

// 在这里实现上述函数...

CourseSet create_empty_set(){
    return 0;
}

void add_course(CourseSet* set, int course_id){
    set[course_id]=1;
    //*set |= (1 << course_id); 
    //要用位操作
}
void remove_course(CourseSet* set, int course_id){
    set[course_id]=0;
    //*set &= ~(1 << course_id);
}

bool has_course(CourseSet set, int course_id){
    return (set>>course_id)&1;
}

void print_courses(CourseSet set){
    for(int i=0;i<sizeof(courses)/sizeof(courses[0]);i++){
        const char* temp=set&(1<<i)?"true":"false";
        printf("%s : %s",courses[i],temp);
    }
    
}

CourseSet union_sets(CourseSet set1, CourseSet set2){
    return set1&set2;
    //这个英文是并集，||
}

CourseSet intersection_sets(CourseSet set1, CourseSet set2){
    return set1||set2;
    //这个英文是交集，&
}

CourseSet difference_sets(CourseSet set1, CourseSet set2){
    return set1^set2;
    //修改：set1^~set2,因为这样得到true的才是选的不一样的，如果没有取反，得到的是选的一样的
}