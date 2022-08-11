function [P,p_f,flag] = trackBot(p_i,c,W)
%{
โปรแกรมจะวนลูปเป็นจำนวนครั้งของคำสั่งโดยใช้ 1:size(c,2)
และใช้คำสั่ง str2double(c(i)) เพื่ออ่านคำสั่งทีละตัว ตัวที่ i
กำหนดทิศทางด้วย direction เริ่มต้นมา = 0
โดยจะกำหนดให้ 0 คือ Up, 1 คือ Left, 2 คือ Down, 3 คือ Right
- เมื่อเจอคำสั่ง 0,2,3 จะทำการเปลี่ยนแปงลค่าของ direction
เมื่อ direction มีการเปลี่ยนแปลงเรื่อยๆ จะใช้คำสั่ง Mod(x,y) 
เพื่อให้ direction อยู่ในช่วงของ 0 1 2 3
- เมื่อเจอคำสั่ง 1,4 จะทำการเปลี่ยน p_f เพิ่ม/ลด ตามทิศทางการเดิน
หากฟังก์ชันถูกเรียกใช้งานด้วย 2 argument หรือ nargin = 2
ซึ่งหมายความว่าไม่มีกำแพง ก็จะทำการเพิ่ม P ตัวสุดท้ายด้วย p_f
แต่ถ้าหาก nargin = 3 จะทำการเช็ค p_f กับ P ด้วยฟังก์ชั่น intersect
เพื่อเช็คว่าจุดหมายที่เดินนั้นชนกับกำแพงหรือไม่โดยใช้ isempty(intersect(W',p_f','row'))
ถ้าเช็คแล้วไม่ชน ก็จะเพิ่ม P ด้วย p_f และ t = t + 1 โดย t
ใช้ในการนับจำนวนของ P ที่เดิน 
แต่ถ้าหาก เช็คแล้วp_f เป็นตำแหน่งเดียวกับ W : p_f
จะเปลี่ยนกลับไปเป็นค่าเดิมก่อนหน้าที่ได้เพิ่มขึ้นมา และ P ก็จะไม่เพิ่มขึ้น
%}
t = 1 ;
direction = 0 ;
flag = 1 ;
P = [];
p_f = [];
%{
check P_i ด้วยการใช้ฟังก์ชัน isequal ถ้าขนาดของp_i ไม่เท่ากับ [2,1]
ให้flag = -11 และและเช็คจำนวนเต้มด้วย ceil(x)
ถ้าปัดเศษขึ้นแล้วไม่เท่ากับตัวเดิมหมายความว่า p_i
ที่รับเข้ามาไม่ใช่จำนวนเต็ม
%}
if ~isequal(size(p_i),[2,1])
    flag = -11 ;
elseif ~isequal(ceil(p_i),p_i)
    flag = -12 ;
end
%{
check C ด้วยฟังก์ชัน ischar(c) ถ้าlogic = 0 flag = -21 นอกจากนี้หาก C
ไม่ว่างปล่าว รันรูปจำนวนทั้งหมดของ C เพื่อใช้ double แปลง srt เป็นเลข ASCII
โดย double('0') = 48 // double('4') = 52
ถ้ามากกว่าหรือน้อยกว่านี้หมายความว่ามีตัวอักษรที่ไม่ใช่เลขหรือไม่ใช่ 0-4
%}
if ischar(c) == 0
    flag = -21;
elseif  ~isempty(c)
    for i = double(c)
        if i > 52 || i <48
            flag = -22;
        end
    end
end

%{
check W 
ถ้าnargin == 3 หมายความว่ารับค่า W มาด้วย จึงจะให้รัน condition นี้
เช็คขนาดของ W ที่รับเข้ามา ว่ามี row = 2 หรือไม่ ถ้าไม่ flag = -31
และเช็คจำนวนเต็มด้วยฟังก์ชั่น isequal(ceil(W),W) ถ้าไม่เท่ากัน flag = -32

เช็คจุดเริ่มต้นว่าอยู่บนกำแพงหรือไม่โดยถ้าp_i และ W มีขนาดถูกต้อง
ให้ใช้ฟังชั่น intersect ในการเช็คว่าจุดp_i ซ้อนกับกำแพงหรือไม่
ถ้าซ้อนกันให้ flag = -4 
%}
if nargin == 3
    if size(W,1) ~= 2
        flag = -31 ;
    elseif ~isequal(ceil(W),W)
        flag = -32;
    end
    
    if isequal(size(p_i),[2,1]) && size(W,1) == 2
        if ~isempty(intersect(W',p_i','row'))
            flag = -4;
        end
    end
end

if flag == 1
    P = p_i ;
    p_f = p_i;
    for i = 1:size(c,2)
        if str2double(c(i)) == 2
            direction = direction + 1 ;
        elseif str2double(c(i)) == 3
            direction = direction - 1 ;
        elseif str2double(c(i)) == 1 || str2double(c(i)) == 4
            if (mod(direction,4)) == 0
                if str2double(c(i)) == 1
                    p_f = p_f + [0;1];
                elseif str2double(c(i)) == 4
                    p_f = p_f + [0;-1];
                end
                
            elseif (mod(direction,4)) == 1
                if str2double(c(i)) == 1
                    p_f = p_f + [-1;0];
                elseif str2double(c(i)) == 4
                    p_f = p_f + [1;0];
                end
                
            elseif (mod(direction,4)) == 2
                if str2double(c(i)) == 1
                    p_f = p_f + [0;-1];
                elseif str2double(c(i)) == 4
                    p_f = p_f + [0;1];
                end
                
            elseif (mod(direction,4)) == 3
                if str2double(c(i)) == 1
                    p_f = p_f + [1;0];
                elseif str2double(c(i)) == 4
                    p_f = p_f + [-1;0];
                end
            end
            
            if nargin == 2
                P(1,t+1) = p_f(1,1);
                P(2,t+1) = p_f(2,1);
                t = t + 1 ;
            elseif nargin == 3
                if isempty(intersect(W',p_f','row'))
                    P(1,t+1) = p_f(1,1);
                    P(2,t+1) = p_f(2,1);
                    t = t + 1 ;
                else
                    p_f = [P(1,t);P(2,t)] ;
                end
            end
            
        end
    end
    %{
    x_min = min([P(1,:) W(1,:)]);
    x_max = max([P(1,:) W(1,:)]);
    y_min = min([P(2,:) W(2,:)]);
    y_max = max([P(2,:) W(2,:)]);
    ax = axes;
    axis(ax,'equal');
    axis(ax,[x_min-1 x_max+1 y_min-1 y_max+1]);
    hold(ax,'on');
    
    for i = 0:(y_max-y_min)+1
        plot(ax,[x_min-1/2 x_max+1/2],[y_min-1/2+i y_min-1/2+i],'k')
    end
    
    for i = 0:(x_max-x_min)+1
        plot(ax,[x_min-1/2+i x_min-1/2+i],[y_min-1/2 y_max+1/2],'k')
    end
    
    for i = 1:size(P,2)
        if i == 1
            color = [0 1 0];
        elseif i == size(P,2)
            color = [1 0 0];
        else
            color = [1 1 0];
        end
        rectangle('Position',[P(1,i)-1/2,P(2,i)-1/2,1,1],'FaceColor',color)
        
    end
    
    for i = 1:size(W,2)
        rectangle('Position',[W(1,i)-1/2,W(2,i)-1/2,1,1],'FaceColor',[0 0 0])
    end
    
    for i = 1:size(P,2)
        if i~=1
            if all(P(:,i-1) == P(:,1))
                color = [0 1 0];
            elseif all(P(:,i-1) == P(:,end))
                color = [1 0 0];
            else
                color = [1 1 0];
            end
            rectangle('Position',[P(1,i-1)-1/2,P(2,i-1)-1/2,1,1],'FaceColor',color);
        end
        rectangle('Position',[P(1,i)-1/2,P(2,i)-1/2,1,1],'FaceColor',[0 0 1]);
        pause(0.5)
    end
    %}
end
end

