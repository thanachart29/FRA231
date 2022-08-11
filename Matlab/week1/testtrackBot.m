function [P,p_f,flag] = testtrackBot(p_i,c,W)
t = 1 ;
direction = 0 ;
flag = 1 ;
P = [];
p_f = [];
%check P_i
if ~isequal(size(p_i),[2,1])
    flag = -11 ;
elseif ~isequal(ceil(p_i),p_i)
    flag = -12 ;
end
%check C
%double('0') = 48 // double('4') = 52
if ischar(c) == 0
    flag = -21;
elseif  ~isempty(c)
    for i = double(c)
        if i > 52 || i <48
            flag = -22;
        end
    end
end

%check W
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
            
            if isempty(intersect(W',p_f','row'))
                P(1,t+1) = p_f(1,1);
                P(2,t+1) = p_f(2,1);
                t = t + 1 ;
            else
                p_f = [P(1,t);P(2,t)] ;
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

