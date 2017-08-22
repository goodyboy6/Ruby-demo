require './tool.rb'





#----------module:mix-in---------------
class Person
	include Tool;
end

puts Person.new.show_tip
puts Tool.say

#----------::-----------------
class Male
	class Student
		AGE = 18
		
		def like
			"play games"
		end
	end
end


puts Male::Student::AGE 
puts "like #{Male::Student.new.like}"


#-------block---------------

[1,2,3].each do |e|
	puts e
end

class Female

	#def give(name, hash, &block)
	#	tmp = block.call
	#	puts "#{name} like #{hash[:what]} #{block.call}";
	#end

	#与上方法等价
	def give(name, hash)
		temp = yield
                puts "#{name} like #{hash[:what]} #{temp}";
        end
end

# 以下三种写法等价

#Female.new.give("I", {:what=>"coffe", :count=>"2", :unit=>"cup"}) {"testes nice"}
 
#Female.new.give("I", {:what=>"coffe", :count=>"2", :unit=>"cup"}) do "testes nice .." end

Female.new.give "I", :what=>"apple", :count=>"2"  do " ... testes nice" end













