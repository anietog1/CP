#! /usr/bin/ruby

gets
input = gets.chomp.split ' '
input.map! { |word| word.to_i  }

i = 0
j = 0
ans = 0

while j < input.size - 1
  if input[j + 1] <= 2 * input[j]
    j += 1
  else
    ans = [ans, j - i + 1].max
    j += 1
    i = j
  end
end

ans = [ans, j - i + 1].max

puts ans
