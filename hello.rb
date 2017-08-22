puts "hello world!"

class Apple

@@from = "China"

attr_accessor 'color'

def setNewColor= color
@color = color;
end

def change_from= name
@@from = name
end

def get_from
@@from
end



end

apple = Apple.new;
apple.color = 'red';
apple.setNewColor = 'blue';
apple.change_from = "Japan"


puts "apple color is #{apple.color} #{apple.get_from}" 
puts "XXX is from #{Apple.new.get_from}"
